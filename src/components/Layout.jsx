import React from "react";
import Navbar from "./Navbar";

export default function Layout({ children }) {
  return (
    <>
      <div className="relative h-full bg-slate-800 ">
        <div className="relative pt-6 h-full">
          <Navbar />
          <div className="h-full bg-slate-800">{children}</div>
        </div>
      </div>
    </>
  );
}
