import React from "react";
import { useTranslation } from "react-i18next";
const metrics = [
  {
    id: 1,
    stat: "8K+",
    emphasis: "Companies",
    rest: "use laoreet amet lacus nibh integer quis.",
  },
  {
    id: 2,
    stat: "25K+",
    emphasis: "Countries around the globe",
    rest: "lacus nibh integer quis.",
  },
  {
    id: 3,
    stat: "98%",
    emphasis: "Customer satisfaction",
    rest: "laoreet amet lacus nibh integer quis.",
  },
  {
    id: 4,
    stat: "12M+",
    emphasis: "Issues resolved",
    rest: "lacus nibh integer quis.",
  },
];

export default function About() {
  const { t } = useTranslation();

  return (
    <div
      className="relative bg-slate-800 mt-8 bg-fixed"
      id="about"
      style={{
        backgroundImage: `url("https://images.unsplash.com/photo-1530469353049-18df0403f42b?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=3518&q=80")`,
      }}
    >
      <div className="absolute inset-x-0 bottom-0 top-0 h-full">
        <div
          className="h-full w-full object-cover opacity-25 xl:absolute xl:inset-0 "
          alt="People working on laptops"
        />
        <div className="absolute inset-0 bg-gradient-to-r from-slate-900 to-green-900 opacity-90" />
        <div
          aria-hidden="true"
          className="absolute inset-x-0 top-0 h-32 bg-gradient-to-b from-slate-800 xl:inset-y-0 xl:left-0 xl:h-full xl:w-32 xl:bg-gradient-to-r"
        />
        <div
          aria-hidden="true"
          className="absolute  top-0 h-32 bg-gradient-to-b from-slate-800 xl:inset-y-0 xl:right-0 xl:h-full xl:w-32 xl:bg-gradient-to-l"
        />
        <div
          aria-hidden="true"
          className="absolute inset-x-0 top-0 h-28 from-slate-800 bg-gradient-to-b"
        />
        <div
          aria-hidden="true"
          className="absolute inset-x-0 bottom-0 h-28 from-slate-800 bg-gradient-to-t"
        />
      </div>
      <div className="max-w-4xl mx-auto px-4 sm:px-6 lg:max-w-7xl lg:px-8 xl:grid xl:grid-cols-2 xl:grid-flow-col-dense xl:gap-x-8">
        <div className="relative pt-12 pb-64 sm:pt-24 sm:pb-64 xl:col-start-1 xl:pb-24">
          <h2 className="text-5xl font-bold tracking-wide uppercase">
            <span className="bg-gradient-to-r from-green-400 to-yellow-300 bg-clip-text text-transparent">
              {t("ABOUT")}
            </span>
          </h2>
          <p className="mt-3 text-3xl font-extrabold text-white">
            Lorem ipsum dolor sit amet consectetur adipisicing elit. Quas,
            asperiores!
          </p>
          <p className="mt-5 text-lg text-gray-300">
            Rhoncus sagittis risus arcu erat lectus bibendum. Ut in adipiscing
            quis in viverra tristique sem. Ornare feugiat viverra eleifend fusce
            orci in quis amet. Sit in et vitae tortor, massa. Dapibus laoreet
            amet lacus nibh integer quis. Eu vulputate diam sit tellus quis at.
          </p>
          <div className="mt-12 grid grid-cols-1 gap-y-12 gap-x-6 sm:grid-cols-2">
            {metrics.map((item) => (
              <p key={item.id}>
                <span className="block text-2xl font-bold text-white">
                  {item.stat}
                </span>
                <span className="mt-1 block text-base text-gray-300">
                  <span className="font-medium text-white">
                    {item.emphasis}
                  </span>{" "}
                  {item.rest}
                </span>
              </p>
            ))}
          </div>
        </div>
      </div>
    </div>
  );
}
