import React, { useState } from "react";
import { useNavigate } from "react-router-dom";
import { useDispatch } from "react-redux";
import { register } from "../redux/features/authSlice";
import LogoLaser from "../assets/laser.png";
import { useTranslation } from "react-i18next";
import { Link } from "react-router-dom";

export default function Register() {
  const { t } = useTranslation();
  const [name, setName] = useState("");
  const [lastname, setLastName] = useState("");
  const [email, setEmail] = useState("");
  const [password, setConfirmPassword] = useState("");
  const [confirmPassword, setPassword] = useState("");
  const navigate = useNavigate();
  const dispatch = useDispatch();

  const Send = (e) => {
    e.preventDefault();

    dispatch(register({ name, lastname, email, password }));

    navigate("/login");
  };

  return (
    <>
      <div className="min-h-full flex bg-gradient-to-br from-green-700 to-yellow-500">
        <div className="flex-1 flex flex-col justify-center py-12 px-4 sm:px-6 lg:flex-none lg:px-20 xl:px-24">
          <div className="mx-auto w-full max-w-sm lg:w-96">
            <div>
              <img src={LogoLaser} alt="Laser" className="object-scale-down" />
              <h2 className="mt-6 text-3xl font-extrabold text-slate-50">
                {t("SIGNUP_MESSAGE")}
              </h2>
            </div>

            <div className="mt-8">
              <div className="mt-6">
                <form className="space-y-2" onSubmit={Send}>
                  <div className="grid grid-cols-2 gap-1">
                    <div>
                      <label
                        htmlFor="name"
                        className="block text-sm font-medium text-yellow-200"
                      >
                        {t("FIRST_NAME")}
                      </label>
                      <div className="mt-1">
                        <input
                          id="name"
                          name="name"
                          type="text"
                          autoComplete="name"
                          required
                          className="appearance-none block w-full px-3 py-2 border border-gray-300 rounded-md shadow-sm placeholder-gray-400 focus:outline-none focus:ring-indigo-500 focus:border-indigo-500 sm:text-sm"
                          onChange={(e) => setName(e.target.value)}
                        />
                      </div>
                    </div>
                    <div>
                      <label
                        htmlFor="lastname"
                        className="block text-sm font-medium text-yellow-200"
                      >
                        {t("LAST_NAME")}
                      </label>
                      <div className="mt-1">
                        <input
                          id="lastname"
                          name="lastname"
                          type="text"
                          autoComplete="lastname"
                          required
                          className="appearance-none block w-full px-3 py-2 border border-gray-300 rounded-md shadow-sm placeholder-gray-400 focus:outline-none focus:ring-indigo-500 focus:border-indigo-500 sm:text-sm"
                          onChange={(e) => setLastName(e.target.value)}
                        />
                      </div>
                    </div>
                  </div>
                  <div>
                    <label
                      htmlFor="email"
                      className="block text-sm font-medium text-yellow-200"
                    >
                      {t("EMAIL")}
                    </label>
                    <div className="mt-1">
                      <input
                        id="email"
                        name="email"
                        type="email"
                        autoComplete="email"
                        required
                        className="appearance-none block w-full px-3 py-2 border border-gray-300 rounded-md shadow-sm placeholder-gray-400 focus:outline-none focus:ring-indigo-500 focus:border-indigo-500 sm:text-sm"
                        onChange={(e) => setEmail(e.target.value)}
                      />
                    </div>
                  </div>

                  <div className="space-y-1">
                    <label
                      htmlFor="password"
                      className="block text-sm font-medium text-yellow-200"
                    >
                      {t("PASSWORD")}
                    </label>
                    <div className="mt-1">
                      <input
                        id="password"
                        name="password"
                        type="password"
                        autoComplete="current-password"
                        required
                        className="appearance-none block w-full px-3 py-2 border border-gray-300 rounded-md shadow-sm placeholder-gray-400 focus:outline-none focus:ring-indigo-500 focus:border-indigo-500 sm:text-sm"
                        onChange={(e) => setPassword(e.target.value)}
                      />
                    </div>
                  </div>
                  <div className="space-y-1">
                    <label
                      htmlFor="confirm-password"
                      className="block text-sm font-medium text-yellow-200"
                    >
                      {t("CONFIRM_PASSWORD")}
                    </label>
                    <div className="mt-1">
                      <input
                        id="confirm-password"
                        name="confirm-password"
                        type="password"
                        required
                        className="appearance-none block w-full px-3 py-2 border border-gray-300 rounded-md shadow-sm placeholder-gray-400 focus:outline-none focus:ring-indigo-500 focus:border-indigo-500 sm:text-sm"
                        onChange={(e) => setConfirmPassword(e.target.value)}
                      />
                    </div>
                  </div>

                  <div>
                    <button
                      type="submit"
                      className="w-full flex justify-center py-2 px-4 border border-transparent rounded-md shadow-sm text-sm font-medium text-white bg-indigo-600 hover:bg-indigo-700 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-indigo-500"
                    >
                      {t("SIGNUP")}
                    </button>
                    <p className="text-yellow-50">
                      {t("HAVE_ACCOUNT")}{" "}
                      <Link
                        to="/login"
                        className="text-green-200 hover:text-green-300"
                      >
                        {" "}
                        {t("LOGIN")}
                      </Link>
                    </p>
                  </div>
                </form>
              </div>
            </div>
          </div>
        </div>
        <div className="hidden lg:block relative w-0 flex-1">
          <img
            className="absolute inset-0 h-full w-full object-cover"
            src="https://images.unsplash.com/photo-1591523499532-95d3e58728c6?ixlib=rb-1.2.1&ixid=MnwxMjA3fDB8MHxwaG90by1wYWdlfHx8fGVufDB8fHx8&auto=format&fit=crop&w=1074&q=80"
            alt=""
          />
        </div>
      </div>
    </>
  );
}
