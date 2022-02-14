import { Menu, Transition } from "@headlessui/react";
import { BellIcon } from "@heroicons/react/outline";
import React, { Fragment, useState } from "react";
import { selectLanguage, setLanguage } from "../redux/features/appSlice";
import flagEs from "../assets/es.png";
import flagEn from "../assets/en.png";
import { useDispatch, useSelector } from "react-redux";
import { useTranslation } from "react-i18next";

function classNames(...classes) {
  return classes.filter(Boolean).join(" ");
}

export default function Language() {
  const { i18n } = useTranslation();
  const [selectedLang, setSelectedLang] = useState("es");

  const handleLanguage = (lng) => {
    setSelectedLang(lng);
    i18n.changeLanguage(lng);
  };

  return (
    <div className="absolute inset-y-0 right-0 flex items-center pr-2 md:static md:inset-auto md:ml-6 md:pr-0">
      {/* Profile dropdown */}
      <>
        <Menu as="div" className="ml-3 relative">
          <div>
            <Menu.Button className="bg-slate-800 flex text-sm rounded-full focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-offset-slate-800 focus:ring-white">
              <span className="sr-only">Open user menu</span>
              <img
                className="h-5 w-5 rounded-full"
                src={selectedLang === "es" ? flagEs : flagEn}
                alt=""
              />
            </Menu.Button>
          </div>
          <Transition
            as={Fragment}
            enter="transition ease-out duration-100"
            enterFrom="transform opacity-0 scale-95"
            enterTo="transform opacity-100 scale-100"
            leave="transition ease-in duration-75"
            leaveFrom="transform opacity-100 scale-100"
            leaveTo="transform opacity-0 scale-95"
          >
            <Menu.Items className="origin-top-right absolute right-0 mt-2 w-48 rounded-md shadow-lg py-1 bg-white ring-1 ring-black ring-opacity-5 focus:outline-none">
              <Menu.Item>
                {({ active }) => (
                  <div
                    onClick={() => {
                      handleLanguage("es");
                    }}
                    className={classNames(
                      active ? "bg-slate-100" : "",
                      "block px-4 py-2 text-sm text-slate-700 cursor-pointer"
                    )}
                  >
                    Spanish
                  </div>
                )}
              </Menu.Item>
              <Menu.Item>
                {({ active }) => (
                  <div
                    onClick={() => {
                      handleLanguage("en");
                    }}
                    className={classNames(
                      active ? "bg-slate-100" : "",
                      "block px-4 py-2 text-sm text-slate-700 cursor-pointer"
                    )}
                  >
                    English
                  </div>
                )}
              </Menu.Item>
            </Menu.Items>
          </Transition>
        </Menu>
      </>
    </div>
  );
}
