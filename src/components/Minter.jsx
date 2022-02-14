import React from "react";

export default function Minter() {
  return (
    <div className="bg-gradient-to-br from-green-600 to-yellow-600 mx-auto mt-6 p-10 rounded-lg shadow-xl flex flex-col">
      <h1 className="text-sky-100 font-bold text-2xl text-center">
        ✈️ LASER Airlines NFT
      </h1>
      <p className="text-center text-green-100 text-lg font-semibold mt-2">
        10.000 NFTs coleccionables con los <br /> mejores aviones del mundo.
      </p>
      <p className="w-96 text-green-50/90">
        Lorem ipsum dolor sit amet consectetur adipisicing elit. Sit, quas!
        Lorem ipsum dolor sit amet, consectetur adipisicing elit. Nemo, vel.
      </p>
      <div className="items-center text-center mt-5 px-3 py-2 shadow-md border border-transparent text-base font-medium rounded-md text-white bg-gradient-to-r from-violet-500 to-sky-700 hover:from-sky-600 hover:to-purple-700 cursor-pointer">
        {"Coming soon..."}
      </div>
    </div>
  );
}
