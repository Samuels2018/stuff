import React, { Suspense } from "react";
import ReactDOM from "react-dom";
import "./index.css";
import reportWebVitals from "./reportWebVitals";
import Root from "./page/Root";
import { Provider } from "react-redux";
import { store } from "./redux/store";
import "./i18n";
ReactDOM.render(
  <React.StrictMode>
    <Suspense fallback={<div className="h-full bg-slate-800">.</div>}>
      <Provider store={store}>
        <Root className="bg-gradient-to-b from-cyan-500 to-blue-500" />
      </Provider>
    </Suspense>
  </React.StrictMode>,
  document.getElementById("root")
);

// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();
