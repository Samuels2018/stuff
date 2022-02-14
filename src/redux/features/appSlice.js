import { createSlice } from "@reduxjs/toolkit";

const initialState = {
  language: "es",
};

const appSlice = createSlice({
  name: "app",
  initialState,
  reducers: {
    setLanguage: (state, action) => {
      state.language = action.payload;
    },
  },
});

const { reducer, actions } = appSlice;

export const { setLanguage } = actions;
export const selectLanguage = (state) => state.app.language;

export default reducer;
