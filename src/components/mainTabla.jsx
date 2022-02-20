import React, {useState, useEffect} from 'react';
import Tabla from './tabla';


function MainTabla() {

	const [data, setData] = useState([]);

	useEffect (() => {

		const askApi = async () => {
			const url = 'https://pokeapi.co/api/v2/pokemon?limit=100&offset=200'

			const res = await fetch(url); 
			const rest = await res.json();

			setData(rest.results);


		}

		askApi();
	}, []);


	console.log(data)


	return (
		<>
			<Tabla data={data} />
		</>

	);
}

export default MainTabla;