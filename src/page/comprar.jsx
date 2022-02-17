import React from 'react';
import Img01 from '../assets/imgNFT/L_122024_laser-airlines.jpg';
import Img02 from '../assets/imgNFT/Laser-Airlines-MD-80.jpg';
import Img03 from '../assets/imgNFT/LASER-Airlines-MD-Venezuela.jpg';

const Comprar = () => {

	return (

		<div className="px-4 py-16 mx-auto sm:max-w-xl md:max-w-full lg:max-w-screen-xl md:px-24 lg:px-8 lg:py-20">
      <div className="grid gap-10 lg:grid-cols-2">
        <div className="flex flex-col justify-center md:pr-8 xl:pr-0 lg:max-w-lg">
          <div className="flex items-center justify-center w-16 h-16 mb-4 rounded-full bg-teal-accent-400">
            <svg className="text-teal-900 w-7 h-7" fill="none" stroke="currentColor" viewBox="0 0 24 24" 
				xmlns="http://www.w3.org/2000/svg">

				<path stroke-linecap="round" 
					stroke-linejoin="round" stroke-width="2" 
					d="M4 16l4.586-4.586a2 2 0 012.828 0L16 16m-2-2l1.586-1.586a2 2 0 012.828 0L20 14m-6-6h.01M6 20h12a2 2 
					0 002-2V6a2 2 0 00-2-2H6a2 2 0 00-2 2v12a2 2 0 002 2z">
				</path>

			</svg>

          </div>
          <div className="max-w-xl mb-6">
            <h2 className="bg-gradient-to-l from-yellow-400 to-green-700 bg-clip-text text-transparent max-w-lg mb-6 font-sans text-3xl font-bold tracking-tight sm:text-4xl sm:leading-none">
              Let us handle
              <br className="hidden md:block" />
              yours{' '}
              <span className="inline-block text-deep-purple-accent-400">
                NFTS
              </span>
            </h2>
            <p className="text-base text-white md:text-lg">
              Sed ut perspiciatis unde omnis iste natus error sit voluptatem
              accusantium doloremque laudantium, totam rem aperiam, eaque ipsa
              quae. explicabo.
            </p>
          </div>

          {/*cantidades*/}

  <div className="flex mx-auto mb-6 items-center justify-center bg-white 
  rounded-3xl border shadow-xl p-2 w-5/6">
    <div className="flex justify-between items-center mb-4">
      
      <div>
        <span className="font-bold text-green-500">1345 de 10.000</span><br />
       
      </div>
    </div>
  </div>


      {/*boton*/}

       <button className="max-w-lg space-y-3 sm:mx-auto lg:max-w-xl">
        <div className="inline-flex items-center px-3 py-2 ml-2 border border-transparent text-base font-medium rounded-md text-white bg-green-600 hover:bg-green-700 hover:scale-105 sm:hover:scale-110">
          <div className="mr-2">
            <svg
              className="w-6 h-6 text-deep-purple-accent-400 sm:w-8 sm:h-8"
              stroke="currentColor"
              viewBox="0 0 52 52"
            >
              <polygon
                strokeWidth="3"
                strokeLinecap="round"
                strokeLinejoin="round"
                fill="none"
                points="29 13 14 29 25 29 23 39 38 23 27 23"
              />
            </svg>
          </div>
          <span className="text-white">
            Mint
          </span>
        </div>
        </button>


        </div>

        <div className="flex items-center justify-center -mx-4 lg:pl-8">
          <div className="flex flex-col items-end px-3">
            <img
              className="object-cover mb-6 rounded shadow-lg h-28 sm:h-48 xl:h-56 w-28 sm:w-48 xl:w-56"
              src={Img01}
              alt=""
            />
            <img
              className="object-cover w-20 h-20 rounded shadow-lg sm:h-32 xl:h-40 sm:w-32 xl:w-40"
              src={Img02}
              alt=""
            />
          </div>
          <div className="px-3">
            <img
              className="object-cover w-40 h-40 rounded shadow-lg sm:h-64 xl:h-80 sm:w-64 xl:w-80"
              src={Img03}
              alt=""
            />
          </div>
        </div>
      </div>
    </div>

	);

}

export default Comprar;

/*

<svg class="w-6 h-6" fill="none" stroke="currentColor" viewBox="0 0 24 24" 
xmlns="http://www.w3.org/2000/svg"><path stroke-linecap="round" 
stroke-linejoin="round" stroke-width="2" 
d="M4 16l4.586-4.586a2 2 0 012.828 0L16 16m-2-2l1.586-1.586a2 2 0 012.828 0L20 14m-6-6h.01M6 20h12a2 2 
0 002-2V6a2 2 0 00-2-2H6a2 2 0 00-2 2v12a2 2 0 002 2z"></path></svg>

*/