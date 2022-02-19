import React, { Fragment, useEffect, useState } from "react";
import { Disclosure, Menu, Transition } from "@headlessui/react";
import { BellIcon, MenuIcon, XIcon } from "@heroicons/react/outline";
import { HashLink } from "react-router-hash-link";
import { Link } from "react-router-dom";
import { ethers } from "ethers";
import { useDispatch, useSelector } from "react-redux";
import { getIsUnlocked, setCurrentAccount } from "../redux/features/web3Slice";
import { logout } from "../redux/features/authSlice";
import LogoLaser from "../assets/laser.png";
import Language from "./Language";
import { useTranslation } from "react-i18next";


// Funciones Auxiliares
const truncateAddress = (address) => {
  return address.slice(0, 6) + "..." + address.slice(-5);
};

function classNames(...classes) {
  return classes.filter(Boolean).join(" ");
}

export default function Navbar() {
  const { t } = useTranslation();
  const [balance, setBalance] = useState(0);
  const { isUnlocked } = useSelector((state) => state.web3);
  const currentAccount = useSelector((state) => state.web3.currentAccount);

  const navigation = [
    { name: "ABOUT", href: "/#about", current: false },
    { name: "COLLECTION", href: "/#collection", current: false },
    { name: "ROADMAP", href: "/#roadmap", current: false },
    { name: "INFO", href: "/#information", current: false },
    { name: "FAQ", href: "/#faq", current: false },
  ];

  const userAuth = useSelector((state) => state.auth);

  const dispatch = useDispatch();

  // Actualizar el balance de la cuenta cuando se detectan cambios en la red
  const updateBalance = async (account) => {
    const { ethereum } = window;
    const provider = new ethers.providers.Web3Provider(ethereum);
    let balance_provider = await provider.getBalance(account);
    balance_provider = ethers.utils.formatEther(balance_provider);
    balance_provider = parseFloat(balance_provider).toFixed(4);
    setBalance(balance_provider);
  };

  const checkWalletIsConnected = async () => {
    const { ethereum } = window;
    if (!ethereum) {
      console.log("Make sure you have metamask installed");
      return false;
    } else {
      console.log("MetaMask is installed");
    }

    dispatch(getIsUnlocked())
      .unwrap()
      .then(async (_isUnlocked) => {
        if (_isUnlocked) {
          const accounts = await ethereum.request({ method: "eth_accounts" });

          if (accounts.length !== 0) {
            const account = accounts[0];
            console.log("Account: ", account);
            dispatch(setCurrentAccount(account));

            updateBalance(account);
          } else {
            console.log("No account found");
          }
        }
      });
  };

  // Manejadores
  const handleAccountChanged = async (accounts) => {
    dispatch(getIsUnlocked())
      .unwrap()
      .then((_isUnlocked) => {
        console.log("Is unlocked: ", _isUnlocked);
        if (accounts.length === 0 && _isUnlocked) {
          dispatch(setCurrentAccount(null));
          setBalance(0);
        } else {
          checkWalletIsConnected();
        }
      })
      .catch(() => {
        console.log("error");
      });
  };

  const handleLogout = () => {
    dispatch(logout());
  };

  const connectWalletHandler = async () => {
    const { ethereum } = window;
    if (!ethereum) {
      console.log("Make sure you have metamask installed");
      alert("Please install MetaMask");
    }

    try {
      const accounts = await ethereum.request({
        method: "eth_requestAccounts",
      });
      dispatch(setCurrentAccount(accounts[0]));
      updateBalance(accounts[0]);
    } catch (error) {
      console.log(error);
    }
  };

  // Componentes axiliares
  const connectWalletButton = () => {
    return (
      <button
        onClick={connectWalletHandler}
        className="hidden md:inline-flex items-center px-4 py-2 border border-transparent text-base font-medium rounded-md text-white bg-slate-600 hover:bg-slate-500"
      >
        <svg
          xmlns="http://www.w3.org/2000/svg"
          viewBox="0 0 212 189"
          className="w-6 h-6 mr-2"
        >
          <g fill="none" fillRule="evenodd">
            <polygon
              fill="#CDBDB2"
              points="60.75 173.25 88.313 180.563 88.313 171 90.563 168.75 106.313 168.75 106.313 180 106.313 187.875 89.438 187.875 68.625 178.875"
            />
            <polygon
              fill="#CDBDB2"
              points="105.75 173.25 132.75 180.563 132.75 171 135 168.75 150.75 168.75 150.75 180 150.75 187.875 133.875 187.875 113.063 178.875"
              transform="matrix(-1 0 0 1 256.5 0)"
            />
            <polygon
              fill="#393939"
              points="90.563 152.438 88.313 171 91.125 168.75 120.375 168.75 123.75 171 121.5 152.438 117 149.625 94.5 150.188"
            />
            <polygon
              fill="#F89C35"
              points="75.375 27 88.875 58.5 95.063 150.188 117 150.188 123.75 58.5 136.125 27"
            />
            <polygon
              fill="#F89D35"
              points="16.313 96.188 .563 141.75 39.938 139.5 65.25 139.5 65.25 119.813 64.125 79.313 58.5 83.813"
            />
            <polygon
              fill="#D87C30"
              points="46.125 101.25 92.25 102.375 87.188 126 65.25 120.375"
            />
            <polygon
              fill="#EA8D3A"
              points="46.125 101.813 65.25 119.813 65.25 137.813"
            />
            <polygon
              fill="#F89D35"
              points="65.25 120.375 87.75 126 95.063 150.188 90 153 65.25 138.375"
            />
            <polygon
              fill="#EB8F35"
              points="65.25 138.375 60.75 173.25 90.563 152.438"
            />
            <polygon
              fill="#EA8E3A"
              points="92.25 102.375 95.063 150.188 86.625 125.719"
            />
            <polygon
              fill="#D87C30"
              points="39.375 138.938 65.25 138.375 60.75 173.25"
            />
            <polygon
              fill="#EB8F35"
              points="12.938 188.438 60.75 173.25 39.375 138.938 .563 141.75"
            />
            <polygon
              fill="#E8821E"
              points="88.875 58.5 64.688 78.75 46.125 101.25 92.25 102.938"
            />
            <polygon
              fill="#DFCEC3"
              points="60.75 173.25 90.563 152.438 88.313 170.438 88.313 180.563 68.063 176.625"
            />
            <polygon
              fill="#DFCEC3"
              points="121.5 173.25 150.75 152.438 148.5 170.438 148.5 180.563 128.25 176.625"
              transform="matrix(-1 0 0 1 272.25 0)"
            />
            <polygon
              fill="#393939"
              points="70.313 112.5 64.125 125.438 86.063 119.813"
              transform="matrix(-1 0 0 1 150.188 0)"
            />
            <polygon
              fill="#E88F35"
              points="12.375 .563 88.875 58.5 75.938 27"
            />
            <path
              fill="#8E5A30"
              d="M12.3750002,0.562500008 L2.25000003,31.5000005 L7.87500012,65.250001 L3.93750006,67.500001 L9.56250014,72.5625 L5.06250008,76.5000011 L11.25,82.1250012 L7.31250011,85.5000013 L16.3125002,96.7500014 L58.5000009,83.8125012 C79.1250012,67.3125004 89.2500013,58.8750003 88.8750013,58.5000009 C88.5000013,58.1250009 63.0000009,38.8125006 12.3750002,0.562500008 Z"
            />
            <g transform="matrix(-1 0 0 1 211.5 0)">
              <polygon
                fill="#F89D35"
                points="16.313 96.188 .563 141.75 39.938 139.5 65.25 139.5 65.25 119.813 64.125 79.313 58.5 83.813"
              />
              <polygon
                fill="#D87C30"
                points="46.125 101.25 92.25 102.375 87.188 126 65.25 120.375"
              />
              <polygon
                fill="#EA8D3A"
                points="46.125 101.813 65.25 119.813 65.25 137.813"
              />
              <polygon
                fill="#F89D35"
                points="65.25 120.375 87.75 126 95.063 150.188 90 153 65.25 138.375"
              />
              <polygon
                fill="#EB8F35"
                points="65.25 138.375 60.75 173.25 90 153"
              />
              <polygon
                fill="#EA8E3A"
                points="92.25 102.375 95.063 150.188 86.625 125.719"
              />
              <polygon
                fill="#D87C30"
                points="39.375 138.938 65.25 138.375 60.75 173.25"
              />
              <polygon
                fill="#EB8F35"
                points="12.938 188.438 60.75 173.25 39.375 138.938 .563 141.75"
              />
              <polygon
                fill="#E8821E"
                points="88.875 58.5 64.688 78.75 46.125 101.25 92.25 102.938"
              />
              <polygon
                fill="#393939"
                points="70.313 112.5 64.125 125.438 86.063 119.813"
                transform="matrix(-1 0 0 1 150.188 0)"
              />
              <polygon
                fill="#E88F35"
                points="12.375 .563 88.875 58.5 75.938 27"
              />
              <path
                fill="#8E5A30"
                d="M12.3750002,0.562500008 L2.25000003,31.5000005 L7.87500012,65.250001 L3.93750006,67.500001 L9.56250014,72.5625 L5.06250008,76.5000011 L11.25,82.1250012 L7.31250011,85.5000013 L16.3125002,96.7500014 L58.5000009,83.8125012 C79.1250012,67.3125004 89.2500013,58.8750003 88.8750013,58.5000009 C88.5000013,58.1250009 63.0000009,38.8125006 12.3750002,0.562500008 Z"
              />
            </g>
          </g>
        </svg>
        {t("CONNECT_WALLET")}
      </button>
    );
  };

  const unlockWalletButton = () => {
    return (
      <button className="hidden md:inline-flex items-center px-4 py-2 border border-transparent text-base font-medium shadow-md shadow-slate-400/20 rounded-md text-white bg-slate-600 hover:bg-slate-700">
        <svg
          xmlns="http://www.w3.org/2000/svg"
          viewBox="0 0 212 189"
          className="w-6 h-6 mr-2"
        >
          <g fill="none" fillRule="evenodd">
            <polygon
              fill="#CDBDB2"
              points="60.75 173.25 88.313 180.563 88.313 171 90.563 168.75 106.313 168.75 106.313 180 106.313 187.875 89.438 187.875 68.625 178.875"
            />
            <polygon
              fill="#CDBDB2"
              points="105.75 173.25 132.75 180.563 132.75 171 135 168.75 150.75 168.75 150.75 180 150.75 187.875 133.875 187.875 113.063 178.875"
              transform="matrix(-1 0 0 1 256.5 0)"
            />
            <polygon
              fill="#393939"
              points="90.563 152.438 88.313 171 91.125 168.75 120.375 168.75 123.75 171 121.5 152.438 117 149.625 94.5 150.188"
            />
            <polygon
              fill="#F89C35"
              points="75.375 27 88.875 58.5 95.063 150.188 117 150.188 123.75 58.5 136.125 27"
            />
            <polygon
              fill="#F89D35"
              points="16.313 96.188 .563 141.75 39.938 139.5 65.25 139.5 65.25 119.813 64.125 79.313 58.5 83.813"
            />
            <polygon
              fill="#D87C30"
              points="46.125 101.25 92.25 102.375 87.188 126 65.25 120.375"
            />
            <polygon
              fill="#EA8D3A"
              points="46.125 101.813 65.25 119.813 65.25 137.813"
            />
            <polygon
              fill="#F89D35"
              points="65.25 120.375 87.75 126 95.063 150.188 90 153 65.25 138.375"
            />
            <polygon
              fill="#EB8F35"
              points="65.25 138.375 60.75 173.25 90.563 152.438"
            />
            <polygon
              fill="#EA8E3A"
              points="92.25 102.375 95.063 150.188 86.625 125.719"
            />
            <polygon
              fill="#D87C30"
              points="39.375 138.938 65.25 138.375 60.75 173.25"
            />
            <polygon
              fill="#EB8F35"
              points="12.938 188.438 60.75 173.25 39.375 138.938 .563 141.75"
            />
            <polygon
              fill="#E8821E"
              points="88.875 58.5 64.688 78.75 46.125 101.25 92.25 102.938"
            />
            <polygon
              fill="#DFCEC3"
              points="60.75 173.25 90.563 152.438 88.313 170.438 88.313 180.563 68.063 176.625"
            />
            <polygon
              fill="#DFCEC3"
              points="121.5 173.25 150.75 152.438 148.5 170.438 148.5 180.563 128.25 176.625"
              transform="matrix(-1 0 0 1 272.25 0)"
            />
            <polygon
              fill="#393939"
              points="70.313 112.5 64.125 125.438 86.063 119.813"
              transform="matrix(-1 0 0 1 150.188 0)"
            />
            <polygon
              fill="#E88F35"
              points="12.375 .563 88.875 58.5 75.938 27"
            />
            <path
              fill="#8E5A30"
              d="M12.3750002,0.562500008 L2.25000003,31.5000005 L7.87500012,65.250001 L3.93750006,67.500001 L9.56250014,72.5625 L5.06250008,76.5000011 L11.25,82.1250012 L7.31250011,85.5000013 L16.3125002,96.7500014 L58.5000009,83.8125012 C79.1250012,67.3125004 89.2500013,58.8750003 88.8750013,58.5000009 C88.5000013,58.1250009 63.0000009,38.8125006 12.3750002,0.562500008 Z"
            />
            <g transform="matrix(-1 0 0 1 211.5 0)">
              <polygon
                fill="#F89D35"
                points="16.313 96.188 .563 141.75 39.938 139.5 65.25 139.5 65.25 119.813 64.125 79.313 58.5 83.813"
              />
              <polygon
                fill="#D87C30"
                points="46.125 101.25 92.25 102.375 87.188 126 65.25 120.375"
              />
              <polygon
                fill="#EA8D3A"
                points="46.125 101.813 65.25 119.813 65.25 137.813"
              />
              <polygon
                fill="#F89D35"
                points="65.25 120.375 87.75 126 95.063 150.188 90 153 65.25 138.375"
              />
              <polygon
                fill="#EB8F35"
                points="65.25 138.375 60.75 173.25 90 153"
              />
              <polygon
                fill="#EA8E3A"
                points="92.25 102.375 95.063 150.188 86.625 125.719"
              />
              <polygon
                fill="#D87C30"
                points="39.375 138.938 65.25 138.375 60.75 173.25"
              />
              <polygon
                fill="#EB8F35"
                points="12.938 188.438 60.75 173.25 39.375 138.938 .563 141.75"
              />
              <polygon
                fill="#E8821E"
                points="88.875 58.5 64.688 78.75 46.125 101.25 92.25 102.938"
              />
              <polygon
                fill="#393939"
                points="70.313 112.5 64.125 125.438 86.063 119.813"
                transform="matrix(-1 0 0 1 150.188 0)"
              />
              <polygon
                fill="#E88F35"
                points="12.375 .563 88.875 58.5 75.938 27"
              />
              <path
                fill="#8E5A30"
                d="M12.3750002,0.562500008 L2.25000003,31.5000005 L7.87500012,65.250001 L3.93750006,67.500001 L9.56250014,72.5625 L5.06250008,76.5000011 L11.25,82.1250012 L7.31250011,85.5000013 L16.3125002,96.7500014 L58.5000009,83.8125012 C79.1250012,67.3125004 89.2500013,58.8750003 88.8750013,58.5000009 C88.5000013,58.1250009 63.0000009,38.8125006 12.3750002,0.562500008 Z"
              />
            </g>
          </g>
        </svg>
        {t("UNLOCK_WALLET")}
      </button>
    );
  };

  // Ver la información de la wallet en el header
  const walletInfo = () => {
    return (
      <div className="hidden md:block bg-slate-800">
        <div className="text-sm text-slate-300">{balance} ETH</div>
        <div className="text-xs text-slate-400 cursor-pointer">
          {truncateAddress(currentAccount)}
        </div>
      </div>
    );
  };
  // Fin componentes axiliares

  // Verificar si la wallet esta conectada.
  useEffect(() => {
    checkWalletIsConnected();
  }, []);

  // Detectar los cambios de red y realizar los ajustes.
  useEffect(() => {
    if (!window.ethereum) {
      console.log("Make sure you have metamask installed");
      return false;
    }
    window.ethereum.on("chainChanged", checkWalletIsConnected);

    return () => {
      window.ethereum.removeListener("chainChanged", checkWalletIsConnected);
    };
  }, []);

  // Detectar los cambios de cuenta, bloqueo de la wallet y cierre de la conexion.
  useEffect(() => {
    if (!window.ethereum) {
      console.log("Make sure you have metamask installed");
      return false;
    }
    window.ethereum.on("accountsChanged", handleAccountChanged);

    return () => {
      window.ethereum.removeListener("accountsChanged", handleAccountChanged);
    };
  }, []);
  return (
    <Disclosure as="nav" className="bg-transparent-800">
      {({ open }) => (
        <>
          <div className="max-w-7xl mx-auto px-2 md:px-6 lg:px-8">
            <div className="relative flex items-center justify-between h-16">
              <div className="absolute inset-y-0 left-0 flex items-center md:hidden">
                {/* Mobile menu button*/}
                <Disclosure.Button className="inline-flex items-center justify-center p-2 rounded-md text-slate-400 hover:text-white hover:bg-slate-700 focus:outline-none focus:ring-2 focus:ring-inset focus:ring-white">
                  <span className="sr-only">Open main menu</span>
                  {open ? (
                    <XIcon className="block h-6 w-6" aria-hidden="true" />
                  ) : (
                    <MenuIcon className="block h-6 w-6" aria-hidden="true" />
                  )}
                </Disclosure.Button>
              </div>
              <div className="flex-1 flex items-center justify-center md:items-stretch md:justify-start">
                <Link className="flex-shrink-0 flex items-center" to={"/"}>
                  <img src={LogoLaser} alt="" className="h-8" />
                  <span className="ml-2 text-slate-100 font-semibold">
                    Laser Airlines
                  </span>
                </Link>
                <div className="hidden md:block md:ml-6">
                  <div className="flex space-x-4">
                    {navigation.map((item) => (
                      <HashLink
                        key={item.name}
                        to={item.href}
                        className={classNames(
                          item.current
                            ? "bg-slate-900 text-white"
                            : "text-slate-300 hover:bg-slate-700 hover:text-white",
                          "px-3 py-2 rounded-md text-sm font-medium"
                        )}
                        aria-current={item.current ? "page" : undefined}
                      >
                        {t(item.name)}
                      </HashLink>
                    ))}
                  </div>
                </div>
              </div>
              <div className="absolute inset-y-0 right-0 flex items-center pr-2 md:static md:inset-auto md:ml-6 md:pr-0">
                {/* Profile dropdown */}
                
                  <>
                    {!isUnlocked
                      ? unlockWalletButton()
                      : currentAccount
                      ? walletInfo()
                      : connectWalletButton()}
                    
                    <Menu as="div" className="ml-3 relative">
                      
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
                              <a
                                href="/"
                                className={classNames(
                                  active ? "bg-slate-100" : "",
                                  "block px-4 py-2 text-sm text-slate-700"
                                )}
                              >
                                {t("PROFILE")}
                              </a>
                            )}
                          </Menu.Item>
                          <Menu.Item>
                            {({ active }) => (
                              <a
                                href="/"
                                className={classNames(
                                  active ? "bg-slate-100" : "",
                                  "block px-4 py-2 text-sm text-slate-700"
                                )}
                              >
                                {t("SETTINGS")}
                              </a>
                            )}
                          </Menu.Item>

                        {/*aqui iba el logout*/}
                          
                        </Menu.Items>
                      </Transition>
                    </Menu>
                  </>
                {/*aqui iba el el login y register*/}


                {/*aqui iba el logo de la imagen de usuario*/}

              </div>
              <Language />
            </div>
          </div>

          <Disclosure.Panel className="md:hidden">
            <div className="px-2 pt-2 pb-3 space-y-1">
              {navigation.map((item) => (
                <Disclosure.Button
                  key={item.name}
                  as="a"
                  href={item.href}
                  className={classNames(
                    item.current
                      ? "bg-slate-900 text-white"
                      : "text-slate-300 hover:bg-slate-700 hover:text-white",
                    "block px-3 py-2 rounded-md text-base font-medium"
                  )}
                  aria-current={item.current ? "page" : undefined}
                >
                  {item.name}
                </Disclosure.Button>
              ))}
            </div>
          </Disclosure.Panel>
        </>
      )}
    </Disclosure>
  );
}


/*
logo de la imagen d usuario
<div>
                        <Menu.Button className="bg-slate-800 flex text-sm rounded-full focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-offset-slate-800 focus:ring-white">
                          <span className="sr-only">Open user menu</span>
                          <img
                            className="h-8 w-8 rounded-full"
                            src="https://images.unsplash.com/photo-1472099645785-5658abf4ff4e?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=facearea&facepad=2&w=256&h=256&q=80"
                            alt=""
                          />
                        </Menu.Button>
                      </div>

logout

<Menu.Item>
                            {({ active }) => (
                              <a
                                href="/"
                                onClick={handleLogout}
                                className={classNames(
                                  active ? "bg-slate-100" : "",
                                  "block px-4 py-2 text-sm text-slate-700"
                                )}
                              >
                                {t("LOGOUT")}
                              </a>
                            )}
                          </Menu.Item>

login

<>
                    <Link
                      to="/login"
                      className="text-base font-medium text-white hover:text-gray-300"
                    >
                      {t("LOGIN")}
                    </Link>
                    <Link
                      to="/register"
                      className="inline-flex items-center px-3 py-2 ml-2 border border-transparent text-base font-medium rounded-md text-white bg-green-600 hover:bg-green-700"
                    >
                      {t("SIGNUP")}
                    </Link>
                  </>


            campana de notificacion

*/