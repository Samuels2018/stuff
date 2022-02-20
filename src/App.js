import React, {useState, useEffect} from 'react';
import MainTabla from './components/mainTabla';
import Image from './components/image';
import {
  Route,
  BrowserRouter as Router,
  Routes,
  Navigate,
  useLocation,
} from "react-router-dom";


function App() {


	return (

		<Router>
			<Routes>
			 	<Route path="/" element={<MainTabla />} />
			 	<Route path="/image" element={<Image />} />
			</Routes>
		</Router>

	);
}

export default App;