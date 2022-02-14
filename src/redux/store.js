import { configureStore } from "@reduxjs/toolkit";
import authReducer from "./features/authSlice";
import messageReducer from "./features/messageSlice";
import web3Reducer from "./features/web3Slice";
import appReducer from "./features/appSlice";

export const store = configureStore({
  reducer: {
    auth: authReducer,
    message: messageReducer,
    web3: web3Reducer,
    app: appReducer,
  },
});
