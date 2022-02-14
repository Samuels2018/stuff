import clientAxios from "../config/axios";
import authHeader from "./auth-header";

const getPublicContent = () => {
  return clientAxios.get("/all");
};

const getUserData = () => {
  return clientAxios.get("/log", { headers: authHeader() });
};

const userService = {
  getPublicContent,
  getUserData,
};

export default userService;
