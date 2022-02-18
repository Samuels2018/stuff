import clientAxios from "../config/axios";
import Cookies from "js-cookie";

const register = (first_name, email, password, password_confirm) => {
  var bodyFormData = new FormData();
  bodyFormData.set("first_name", first_name);
  bodyFormData.set("email", email);
  bodyFormData.set("password", password);
  bodyFormData.set("password_confirm", password_confirm);

  return clientAxios
    .post("/sign-up", bodyFormData, {
      headers: { "Content-Type": "multipart/form-data" },
    })
    .then((response) => {
      console.log(response.data);
    });
};

// Para usarlo con el backend
/*const login = (email, password) => {
  return clientAxios
    .post("/signin", {
      email,
      password,
    })
    .then((response) => {
      if (response.data.token) {
        localStorage.setItem("user", JSON.stringify(response.data));
      }
      return response.data;
    });
};
*/

// Backend
const login = (email, password) => {
  var bodyFormData = new FormData();

  bodyFormData.set("email", email);
  bodyFormData.set("password", password);
  return clientAxios
    .post("/login", bodyFormData, {
      headers: { "Content-Type": "multipart/form-data" },
    })
    .then((response) => {
      console.log(response.data);
      if (response.data.status === 200) {
        let token = Cookies.get("remember_token");
        console.log(token);
        console.log(response.data);
        localStorage.setItem("user", JSON.stringify({ token: true }));
        console.log(response.data);
      }
      return { token: true };
    });
};

// Backend de prueba
/*
const login = (email, password) => {
  return clientAxios.get("/signin").then((response) => {
    if (response.data.token) {
      localStorage.setItem("user", JSON.stringify(response.data));
    }
    return response.data;
  });
};
*/
const logout = () => {
  localStorage.removeItem("user");
  return clientAxios.get("/logout").then((response) => {
    if (response.data.status === 200) {
      console.log(response.data);
    }
    return { token: true };
  });
};

const authService = {
  register,
  login,
  logout,
};

export default authService;
