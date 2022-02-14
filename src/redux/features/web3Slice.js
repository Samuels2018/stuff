import { createSlice, createAsyncThunk } from "@reduxjs/toolkit";
import { ethers } from "ethers";
import axios from "axios";
import abi from "../../config/contract/abi.json";
const contractAddress = "0xCfE0F9c47D23b2B2d3b5A7Bd4E09495c8a1fbb5c";

export const getCollection = createAsyncThunk(
  "web3/getCollection",
  async (_, thunkAPI) => {
    const { ethereum } = window;
    if (!ethereum) {
      console.log("Make sure you have metamask installed");
      return [];
    }
    const provider = new ethers.providers.Web3Provider(ethereum);
    const signer = provider.getSigner();

    const nftContract = new ethers.Contract(contractAddress, abi, signer);

    console.log("Getting count of NFT...");

    try {
      let countNFT = await nftContract.tokenCounter();
      countNFT = parseInt(countNFT._hex, 16);
      let listNFT = [];

      for (let i = 0; i < countNFT; i++) {
        const nftURI = await nftContract.tokenURI(i);
        const nftOwner = await nftContract.ownerOf(i);
        if (
          nftOwner.toString().toLowerCase() ===
          String(thunkAPI.getState().web3.currentAccount).toLowerCase()
        ) {
          console.log("Found NFT");
          let nftMetadata = await axios.get(nftURI);
          if (typeof nftMetadata.data === "object") {
            listNFT.push({
              id: i,
              data: nftMetadata.data,
            });
          }
        }
      }
      return listNFT;
    } catch (error) {
      console.log("Something went wrong", error);
      return [];
    }
  }
);

export const getIsUnlocked = createAsyncThunk("web3/getIsLocked", async () => {
  try {
    const response = await window.ethereum._metamask.isUnlocked();
    return response;
  } catch (error) {
    console.log("Something went wrong");
    return false;
  }
});

const initialState = {
  isUnlocked: false,
  currentAccount: "",
  nftCollection: null,
  contract: "0xCfE0F9c47D23b2B2d3b5A7Bd4E09495c8a1fbb5c",
};

const web3Slice = createSlice({
  name: "web3",
  initialState,
  reducers: {
    setCurrentAccount: (state, action) => {
      state.currentAccount = action.payload;
    },
  },
  extraReducers: {
    [getIsUnlocked.fulfilled]: (state, action) => {
      state.isUnlocked = action.payload;
    },
    [getIsUnlocked.rejected]: (state, action) => {
      state.isUnlocked = false;
    },
    [getCollection.fulfilled]: (state, action) => {
      state.nftCollection = action.payload;
    },
    [getCollection.rejected]: (state, action) => {
      state.nftCollection = null;
    },
  },
});

export const { setCurrentAccount } = web3Slice.actions;

export const { selectCurrentAccount } = (state) => state.web3.currentAccount;

const { reducer } = web3Slice;

export default reducer;
