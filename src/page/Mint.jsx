import React from "react";
import Minter from "../components/Minter";

export default function Mint() {
  return (
    <div className="bg-gradient-to-b from-slate-800 to-green-600 flex-1 h-full">
      <div className="mx-auto max-w-7xl lg:px-8 h-full flex flex-col space-y-4 items-center">
        <Minter />
      </div>
    </div>
  );
}
