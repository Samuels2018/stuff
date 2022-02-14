import React from "react";
import { useTranslation } from "react-i18next";
import { Link } from "react-router-dom";
import About from "../components/About";
import CollectionLanding from "../components/CollectionLanding";
import Especificaciones from "../components/Especificaciones";
import Faqs from "../components/Faqs";
import Footer from "../components/Footer";
import LandingCollection from "../components/LandingCollection";
import Navbar from "../components/Navbar";
import Timeline from "../components/Timeline";
import LogoAircraft from "../assets/aircraft.png";

export default function Landing() {
  const { t } = useTranslation();

  return (
    <>
      <div className="relative h-full">
        <div
          className="hidden lg:block lg:absolute lg:inset-y-0 lg:h-full lg:w-full"
          aria-hidden="true"
        >
          <div className="relative h-full max-w-7xl mx-auto">
            <svg
              className="absolute right-full transform translate-y-1/4 translate-x-1/4 lg:translate-x-1/2"
              width={404}
              height={784}
              fill="none"
              viewBox="0 0 404 784"
            >
              <defs>
                <pattern
                  id="f210dbf6-a58d-4871-961e-36d5016a0f49"
                  x={0}
                  y={0}
                  width={20}
                  height={20}
                  patternUnits="userSpaceOnUse"
                >
                  <rect
                    x={0}
                    y={0}
                    width={4}
                    height={4}
                    className="text-slate-700"
                    fill="currentColor"
                  />
                </pattern>
              </defs>
              <rect
                width={404}
                height={784}
                fill="url(#f210dbf6-a58d-4871-961e-36d5016a0f49)"
              />
            </svg>
            <svg
              className="absolute left-full transform -translate-y-3/4 -translate-x-3/4 md:-translate-y-2/4 lg:-translate-x-full"
              width={404}
              height={784}
              fill="none"
              viewBox="0 0 404 784"
            >
              <defs>
                <pattern
                  id="5d0dd344-b041-4d26-bec4-8d33ea57ec9b"
                  x={0}
                  y={0}
                  width={20}
                  height={20}
                  patternUnits="userSpaceOnUse"
                >
                  <rect
                    x={0}
                    y={0}
                    width={4}
                    height={4}
                    className="text-slate-700"
                    fill="currentColor"
                  />
                </pattern>
              </defs>
              <rect
                width={404}
                height={784}
                fill="url(#5d0dd344-b041-4d26-bec4-8d33ea57ec9b)"
              />
            </svg>
          </div>
        </div>
        <div className="relative pt-6">
          <Navbar />

          <main className=" mx-auto md:max-w-7xl pt-20 md:pt-40 px-4 h-full md:h-screen">
            <div className="text-center">
              <h1 className="text-xl tracking-tight font-extrabold text-slate-200 sm:text-3xl md:text-3xl">
                <span className="block text-slate-200 sm:text-9xl text-7xl font-semibold">
                  LASER
                </span>{" "}
                <span className="block sm:text-6xl text-5xl text-green-500 tracking-normal">
                  Airlines <span className="text-yellow-500">|</span>{" "}
                  <span className="text-green-600">NFT</span>
                </span>
              </h1>
              <img
                className="md:-mt-16 object-scale-down"
                src={LogoAircraft}
                alt=""
              />
              <p className="mt-3 max-w-md mx-auto text-base text-slate-400 sm:text-lg md:mt-5 md:text-xl md:max-w-3xl">
                Anim aute id magna aliqua ad ad non deserunt sunt. Qui irure qui
                lorem cupidatat commodo. Elit sunt amet fugiat veniam occaecat
                fugiat aliqua.
              </p>
              <div className="mt-5 max-w-md mx-auto sm:flex sm:justify-center md:mt-8">
                <div className="rounded-md shadow">
                  <Link
                    to="/mint"
                    className="w-full flex items-center justify-center px-8 py-3 border border-transparent text-base font-medium rounded-md text-yellow-50 bg-green-600 hover:bg-green-700 shadow-lg shadow-green-500/50 md:py-4 md:text-3xl md:px-10"
                  >
                    {t("BUY_AIRCRAFT")}
                  </Link>
                </div>
              </div>
            </div>
          </main>
          <About />
          <LandingCollection />
          <CollectionLanding />
          <Timeline />
          <Especificaciones />
          <Faqs />
          <Footer />
        </div>
      </div>
    </>
  );
}
