import React from "react";
import { Route, BrowserRouter as Router, Routes } from "react-router-dom";
import Layout from "../components/Layout";
import Mint from "./Mint";
import Landing from "./Landing";

export default function Root() {
  return (
    <Router>
      <Routes>
        <Route path="/" element={<Landing />} />
       
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
