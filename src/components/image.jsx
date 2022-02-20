import React, {useState, useEffect} from 'react';

const Image = () => {

	const [apiFetch, setApiFetch] = useState([]);
	const [image, setImage] = useState([]);
	const [apiPromise, setApiPromise] = useState([]);
	const [apiAsync, setApiAsync] = useState([]);

	// todo estas funciones se pueden exportar si se colocan en pagina aparte
	// luego de esto se importarian por aca y se le haria la llamado por 
	//el useEffect pero para motivos de esa prueba me parecio irrelevanta
	// tambien hice todas las consultas requeridas pero legalmente solo muestro
	// una por el browser ya que es solo una demosracion de como se hacen dichas consultas

	useEffect (() => {

		const askApi = async () => {
			const url = 'http://api.giphy.com/v1/gifs/random?api_key=LdJCBTRkYlhxnLQT5A9GmjkghDMcQrpN';

			const res = await fetch(url); 
			const rest = await res.json();

			console.log(rest.data)
			setApiAsync(rest.data);
			setImage(rest.data.images.downsized.url)


		}

		const reqFetch = () => {
			const url = 'http://api.giphy.com/v1/gifs/random?api_key=LdJCBTRkYlhxnLQT5A9GmjkghDMcQrpN';
			fetch (url)
			.then((res) => {
				let rep = res.json()
				setApiFetch(rep)
			})
		}

		const promise = () => {
			const url = 'http://api.giphy.com/v1/gifs/random?api_key=LdJCBTRkYlhxnLQT5A9GmjkghDMcQrpN';
			return new Promise((resolve, reject) => {
				const req = new XMLHttpRequest();
				req.open('GET', url);

				req.onload = function() {
					if(req.status == 200) {
						resolve(req.response);
						setApiPromise(req.response);

					}

					else reject(Error(req.statusText))
				}

				req.onerror = function() {
					reject(Error("Error de red"));
				}

				req.send()
			})
		}

		askApi();
		reqFetch();
		promise();
	}, []);


const {bitly_gif_url,
bitly_url,
content_url,
embed_url,
id,
images,
import_datetime,
is_sticker,
rating,
slug,
source,
source_post_url,
source_tld,
title,
trending_datetime,
type,
url,
user,
username} = apiAsync



	return (
		<>
			<h1>{title}</h1>
			<img src={image} />	
		</>

	)

}

export default Image;