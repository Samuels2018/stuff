import axios from "axios";

// BACKEND
const clientAxios = axios.create({
  baseURL: "http://18.224.8.223:8080/",
});

// TESTING FRONTEND LOCALHOST
/*const clientAxios = axios.create({
  baseURL: "http://localhost:8000/",
});
*/
export default clientAxios;
