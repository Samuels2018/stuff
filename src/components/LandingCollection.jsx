import React from "react";
import { useTranslation } from "react-i18next";

export default function LandingCollection() {
  const { t } = useTranslation();

  return (
    <>
      <div id="collection" className="bg-slate-800 pt-16 lg:py-24">
        <div className="pb-16 bg-slate-800 lg:pb-0 lg:z-10 lg:relative">
          <div className="lg:mx-auto lg:max-w-7xl lg:px-8 lg:grid lg:grid-cols-4 lg:gap-8">
            <div className="cols-span-2 lg:-translate-x-20">
              <div className="relative">
                <div className="absolute top-16 left-28 z-50 -mr-24">
                  <div
                    aria-hidden="true"
                    className="absolute inset-x-0 top-0 h-1/2 bg-slate-800 lg:hidden"
                  />
                  <div className="mx-auto max-w-md px-4 sm:max-w-3xl sm:px-6 lg:p-0 lg:h-full">
                    <div className="aspect-w-10 aspect-h-6 rounded-xl overflow-hidden sm:aspect-w-16 sm:aspect-h-7 lg:aspect-none lg:h-full shadow-lg shadow-sky-800/50">
                      <img
                        className="object-cover lg:h-full lg:w-full"
                        src="https://images.unsplash.com/photo-1531642765602-5cae8bbbf285?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=600&q=80"
                        alt=""
                      />
                    </div>
                  </div>
                </div>
                <div className="aboslute top-0 -mt-5 left-0 z-50">
                  <div
                    aria-hidden="true"
                    className="absolute inset-x-0 top-0 h-1/2 bg-slate-800 lg:hidden"
                  />
                  <div className="mx-auto max-w-md px-4 sm:max-w-3xl sm:px-6 lg:p-0 lg:h-full">
                    <div className="aspect-w-10 aspect-h-8 rounded-xl shadow-lg shadow-sky-700/50 overflow-hidden sm:aspect-w-16 sm:aspect-h-7 lg:aspect-none lg:h-full">
                      <img
                        className="object-cover lg:h-full lg:w-full"
                        src="https://images.unsplash.com/photo-1487553333251-6c8e26d3dc2c?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1587&q=80"
                        alt=""
                      />
                    </div>
                  </div>
                </div>
              </div>
            </div>

            <div className="mt-12 lg:m-0 lg:col-span-3 lg:pl-8">
              <div className="mx-auto max-w-md px-4 sm:max-w-2xl sm:px-6 lg:px-0 lg:py-20 lg:max-w-none">
                <h3 className="block bg-gradient-to-r from-green-400 to-yellow-300 bg-clip-text text-transparent text-5xl font-bold tracking-wide uppercase text-center mt-6">
                  {t("COLLECTION")}
                </h3>
                <blockquote>
                  <div>
                    <svg
                      className="h-12 w-12 text-white opacity-25"
                      fill="currentColor"
                      viewBox="0 0 32 32"
                      aria-hidden="true"
                    >
                      <path d="M9.352 4C4.456 7.456 1 13.12 1 19.36c0 5.088 3.072 8.064 6.624 8.064 3.36 0 5.856-2.688 5.856-5.856 0-3.168-2.208-5.472-5.088-5.472-.576 0-1.344.096-1.536.192.48-3.264 3.552-7.104 6.624-9.024L9.352 4zm16.512 0c-4.8 3.456-8.256 9.12-8.256 15.36 0 5.088 3.072 8.064 6.624 8.064 3.264 0 5.856-2.688 5.856-5.856 0-3.168-2.304-5.472-5.184-5.472-.576 0-1.248.096-1.44.192.48-3.264 3.456-7.104 6.528-9.024L25.864 4z" />
                    </svg>
                    <p className="mt-6 text-2xl font-normal text-slate-200/75">
                      Lorem ipsum dolor sit amet consectetur adipisicing elit.
                      Accusamus, ab hic. Magni itaque veniam rem provident ex
                      sunt in nostrum cum unde quasi, similique soluta alias
                      laborum quia dignissimos dolores obcaecati possimus sit
                      asperiores adipisci odio reiciendis quis fugit
                      perferendis! Eaque excepturi debitis totam labore nulla
                      porro libero, nemo deleniti!
                    </p>
                  </div>
                </blockquote>
              </div>
            </div>
          </div>
        </div>
      </div>
    </>
  );
}
