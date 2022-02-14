import React, { useEffect, useState } from "react";
import LogoLaser from "../assets/laser.png";
import { useTranslation } from "react-i18next";

// Thrid party components
import { Formik, Field, Form, ErrorMessage } from "formik";
import * as Yup from "yup";
import { useNavigate } from "react-router-dom";

// Assets
import { useDispatch, useSelector } from "react-redux";
import { clearMessage } from "../redux/features/messageSlice";
import { login } from "../redux/features/authSlice";

export default function Login(props) {
  const { t } = useTranslation();
  const [loading, setLoading] = useState(false);
  const { isLoggedIn } = useSelector((state) => state.auth);
  //const { message } = useSelector((state) => state.message);

  const navigate = useNavigate();

  const dispatch = useDispatch();

  useEffect(() => {
    dispatch(clearMessage());
  }, [dispatch]);

  const initialValues = {
    email: "",
    password: "",
  };

  const validationSchema = Yup.object().shape({
    email: Yup.string().required("Email is required"),
    password: Yup.string().required("Password is required"),
  });

  const handleLogin = (values) => {
    console.log(values);
    const { email, password } = values;
    setLoading(true);
    dispatch(login(email, password))
      .unwrap()
      .then(() => {
        navigate("/");
      })
      .catch(() => {
        setLoading(false);
      });
  };

  if (isLoggedIn) {
    navigate("/");
  }

  return (
    <>
      <div className="min-h-full flex bg-gradient-to-br from-green-700 to-yellow-500">
        <div className="flex-1 flex flex-col justify-center py-12 px-4 sm:px-6 lg:flex-none lg:px-20 xl:px-24">
          <div className="mx-auto w-full max-w-sm lg:w-96">
            <div>
              <img src={LogoLaser} alt="Laser" className="object-scale-down" />
              <h2 className="mt-6 text-3xl font-extrabold text-slate-50">
                {t("SIGNIN_MESSAGE")}
              </h2>
            </div>

            <div className="mt-8">
              <div className="mt-6">
                <Formik
                  initialValues={initialValues}
                  validationSchema={validationSchema}
                  onSubmit={handleLogin}
                >
                  <Form className="space-y-6">
                    <div>
                      <label
                        htmlFor="email"
                        className="block text-sm font-medium text-yellow-200"
                      >
                        {t("EMAIL")}
                      </label>
                      <div className="mt-1">
                        <Field
                          id="email"
                          name="email"
                          type="email"
                          autoComplete="email"
                          required
                          className="appearance-none block w-full px-3 py-2 border border-gray-300 rounded-md shadow-sm placeholder-gray-400 focus:outline-none focus:ring-green-500 focus:border-green-500 sm:text-sm"
                        />
                        <ErrorMessage
                          name="email"
                          className="text-green-100"
                          component="div"
                        />
                      </div>
                    </div>

                    <div className="space-y-1">
                      <label
                        htmlFor="password"
                        className="block text-sm font-medium text-yellow-200"
                      >
                        Password
                      </label>
                      <div className="mt-1">
                        <Field
                          id="password"
                          name="password"
                          type="password"
                          autoComplete="current-password"
                          required
                          className="appearance-none block w-full px-3 py-2 border border-gray-300 rounded-md shadow-sm placeholder-gray-400 focus:outline-none focus:ring-green-500 focus:border-green-500 sm:text-sm"
                        />
                        <ErrorMessage
                          className="text-green-100"
                          name="password"
                          component="div"
                        />
                      </div>
                    </div>

                    <div className="flex items-center justify-between">
                      <div className="hidden items-center">
                        <input
                          id="remember-me"
                          name="remember-me"
                          type="checkbox"
                          className="h-4 w-4 text-green-600 focus:ring-green-600 border-gray-300 rounded"
                        />
                        <label
                          htmlFor="remember-me"
                          className="ml-2 block text-sm text-gray-900"
                        >
                          Remember me
                        </label>
                      </div>

                      <div className="text-sm">
                        <a
                          href="/forgot-password"
                          className="font-medium text-green-200 hover:text-green-300"
                        >
                          {t("FORGOT_PASSWORD")}
                        </a>
                      </div>
                    </div>

                    <div>
                      <button
                        type="submit"
                        disabled={loading}
                        className="w-full flex justify-center py-2 px-4 border border-transparent rounded-md shadow-sm text-sm font-medium text-yellow-100 hover:text-yellow-100 bg-green-700 hover:bg-green-600 focus:outline-none focus:ring-2 focus:ring-offset-2 focus:ring-green-600"
                      >
                        {t("LOGIN")}
                      </button>
                      <p className="mt-2 text-yellow-100">
                        {t("DONT_HAVE_ACCOUNT")}&nbsp;
                        <a
                          href="/register"
                          className="text-green-200 hover:text-green-300"
                        >
                          {t("REGISTER_IT")}
                        </a>
                      </p>
                    </div>
                  </Form>
                </Formik>
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
