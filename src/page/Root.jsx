import React from "react";
import { Route, BrowserRouter as Router, Routes } from "react-router-dom";
import Layout from "../components/Layout";
import Mint from "./Mint";
import Landing from "./Landing";
import Login from "./Login";
import Register from "./Register";
import Comprar from './comprar';

export default function Root() {
  return (
    <Router>
      <Routes>
        <Route path="/" element={<Landing />} />
        <Route path="/login" element={<Login />} />
        <Route path="/register" element={<Register />} />
        <Route path="/comprar" 
        element={
          <Layout>
            <Comprar />
          </Layout>} 
        />
        <Route
          path="/mint"
          element={
            <Layout>
              <Mint />
            </Layout>
          }
        />
      </Routes>
    </Router>
  );
}
