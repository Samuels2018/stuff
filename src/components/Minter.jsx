import React, { useState } from "react";
import { ethers } from "ethers";
import "../styles/minter.css";
import abi from "../config/contract/abi.json";
import meta from "../assets/metadata/data.json";
import { QuantityPicker } from "react-qty-picker";
import { useSelector } from "react-redux";
import Loader from "./Loader";
import imgA from "../assets/imgNFT/a1.png";
import imgB from "../assets/imgNFT/a2.png";
import imgC from "../assets/imgNFT/a3.png";
import imgD from "../assets/imgNFT/a4.png";
import imgE from "../assets/imgNFT/a5.png";
import imgF from "../assets/imgNFT/a6.png";
import imgG from "../assets/imgNFT/a7.png";
import imgH from "../assets/imgNFT/a8.png";

export default function Minter() {
  const [amountNft, setAmountNft] = useState(1);
  const [status, setStatus] = useState(null);
  const [minting, setMinting] = useState(false);
  const { isUnlocked } = useSelector((state) => state.web3);

  const contractAddress = "0xCfE0F9c47D23b2B2d3b5A7Bd4E09495c8a1fbb5c";

  const getNTFInfo = () => {
    let number = Math.floor(Math.random() * (5 - 0)) + 0;
    return `https://gateway.pinata.cloud/ipfs/${meta[number]}`;
  };

  // Este procedimiento hay que modificarlo, ya que el nuevo contrato debe contemplar mintear varios NFT a la vez.
  const onMintPressed = async () => {
    const { ethereum } = window;
    setMinting(true);
    setStatus(null);
    const provider = new ethers.providers.Web3Provider(ethereum);
    const signer = provider.getSigner();

    const nftContract = new ethers.Contract(contractAddress, abi, signer);

    console.log("Iniciando Mint...");
    let nftInfo = getNTFInfo(); // Instanciamos la transacción
    // Falta por hacer:
    // 1. Obtener la información del resultado de la operacion
    // 2. Mostrar al usuario el resultado de la operacion
    // 3. Una vez que la transaccion se procese exitosamente, actualizar la lista de nfts

    try {
      let nftTxn = await nftContract.mint(nftInfo);
      console.log(nftTxn);
      setStatus(nftTxn.hash);
      setMinting(false);
    } catch (err) {
      console.log("Ha ocurrido un error: " + err);
      setMinting(false);
    }
  };

  return (
    <>
      {
        //Imagenes superor
      }
      <div className="">
        <div className="grid grid-cols-3 md:grid-cols-5 gap-10">
          <img
            src={imgA}
            alt="NFT"
            className="w-32 rounded-xl border-2 border-opacity-70 border-green-500 shadow-xl shadow-green-500/30 mt-14 -mb-10 hidden md:block"
          />
          <img
            src={imgB}
            alt="NFT"
            className="w-32 rounded-xl border-2 border-opacity-70 border-green-500 shadow-xl shadow-green-500/30"
          />
          <img
            src={imgC}
            alt="NFT"
            className="w-32 rounded-xl border-2 border-opacity-70 border-green-500 shadow-xl shadow-green-500/30"
          />
          <img
            src={imgD}
            alt="NFT"
            className="w-32 rounded-xl border-2 border-opacity-70 border-green-500 shadow-xl shadow-green-500/30"
          />
          <img
            src={imgE}
            alt="NFT"
            className="w-32 rounded-xl border-2 border-opacity-70 border-green-500 shadow-xl shadow-green-500/30 mt-14 -mb-10 hidden md:block"
          />
        </div>
      </div>
      <div className="bg-gradient-to-br from-green-600 via-green-700 to-green-800 mx-auto mt-6 p-10 rounded-lg shadow-xl">
        <h1 className="bg-clip-text text-transparent bg-gradient-to-r from-yellow-400 to-green-300 font-bold text-3xl text-center">
          LASER Airlines NFT
        </h1>
        <p className="text-center text-green-100 text-lg font-semibold mt-2">
          10.000 NFTs coleccionables con los <br /> mejores aviones del mundo.
        </p>
        <div className="p-4 bg-clip-content border-green-300/50 border-dashed border-4 rounded-sm mt-4">
          <p className="text-center w-full font-semibold text-2xl bg-clip-text text-transparent bg-gradient-to-r from-green-100 to-green-400">
            7.000 de 10.000
          </p>
          <div className="minter__animation-bar-1 items-center mt-2">
            <span style={{ width: "60%" }}></span>
          </div>
          <QuantityPicker
            width="full"
            smooth
            value={amountNft}
            min={1}
            max={3}
            onChange={(value) => {
              // here value is the final update value of the component
              setAmountNft(value);
            }}
            className="w-full"
          />
          {!isUnlocked ? (
            <button
              disabled
              className="items-center w-full text-center mt-5 px-3 py-2 shadow-md border border-transparent text-base font-medium rounded-md text-slate-900 bg-gradient-to-r from-slate-300 via-sltae-200 to-slate-400 cursor-pointer"
            >
              Please unlock wallet
            </button>
          ) : (
            <button
              className="inline-flex items-center w-full text-center mt-5 px-3 py-2 shadow-md border border-transparent text-base font-semibold rounded-md text-yellow-900 bg-gradient-to-r from-yellow-500 via-yellow-400 to-yellow-600 hover:from-yellow-400 hover:to-yellow-600 cursor-pointer"
              onClick={onMintPressed}
              disabled={minting}
            >
              {minting ? (
                <>
                  <Loader className="w-10 h-10 mr-2 ml-auto text-yellow-200" />
                  <span className="mr-auto">Procesando...</span>
                </>
              ) : (
                <span className="mx-auto">Comprar NFT</span>
              )}
            </button>
          )}

          {status && (
            <a
              href={`https://goerli.etherscan.io/tx/${status}`}
              target="_blank"
              rel="noopener noreferrer"
              className="text-xs text-sky-200 mt-4"
            >
              {status}
            </a>
          )}
        </div>
      </div>
      <div className="grid grid-cols-3 md:grid-cols-5 gap-10">
        <img
          src={imgA}
          alt="NFT"
          className="w-32 rounded-xl border-2 border-opacity-70 border-green-500 shadow-xl shadow-sky-500/30 mb-14 -mt-10 hidden md:block"
        />
        <img
          src={imgB}
          alt="NFT"
          className="w-32 rounded-xl border-2 border-opacity-70 border-green-500 shadow-xl shadow-sky-500/30"
        />
        <img
          src={imgC}
          alt="NFT"
          className="w-32 rounded-xl border-2 border-opacity-70 border-green-500 shadow-xl shadow-sky-500/30"
        />
        <img
          src={imgD}
          alt="NFT"
          className="w-32 rounded-xl border-2 border-opacity-70 border-green-500 shadow-xl shadow-sky-500/30"
        />
        <img
          src={imgE}
          alt="NFT"
          className="w-32 rounded-xl border-2 border-opacity-70 border-green-500 shadow-xl shadow-sky-500/30 mb-14 -mt-10 hidden md:block"
        />
      </div>
    </>
  );
}
