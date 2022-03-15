import {
	ADD_PRODUCT, 
	ADD_PRODUCT_SUCCESS ,
	ADD_PRODUCT_ERR,
	START_DOWNLOAD_PRODUCTS,
	DOWNLOAD_PRODUCTS_SUCCESS,
	DOWNLOAD_PRODUCTS_ERR,
	GET_PRODUCT_DELETE,
	PRODUCT_DELETE_SUCCESS,
	PRODUCT_DELETE_ERR,
	GET_PRODUCT_EDIT,
	PRODUCT_EDIT_SUCCESS,
	PRODUCT_EDIT_ERR,
	START_EDITION_PRODUCT,
	PRODUCT_EDITED_SUCCESS,
	PRODUCT_EDITED_ERR
} from '../types';

import clientAxios from '../config/axios';

// los action son para modificar el state

//crear una funcion principal 
export function creteNewProductAction(product) {
	//dispatch manda a llamar las otras 2 acciones 
	return (dispatch) => {
		dispatch(newProduct())

		//insertar en la api
		clientAxios.post(`/books`, product)
			.then(res => {
				console.log(res);

				//se llama si se inseta correctamente
				dispatch(addNewProductSuccess(product)); 
			})
			.catch(err => {
				console.log(err);

				//si hay un error 
				dispatch(addNewProductErr(err));
			})
	}
}

export const newProduct = () => ({
	type: ADD_PRODUCT
});

export const addNewProductSuccess = product => ({
	type: ADD_PRODUCT_SUCCESS,
	payload: product
});

export const addNewProductErr = err => ({
	type: ADD_PRODUCT_ERR,
	payload: err
});

//obtener listado de productos (consultar api)

export function getProductAction() {
	return (dispatch) => {
		dispatch( getProductsStart() );

		clientAxios.get(`/books`)
			.then(res => {
				console.log(res);
				dispatch( downloadProductsSuccess(res.data) )
			})
			.catch(err => {
				console.log(err);
				dispatch( downloadProductsErr() )
			})
	}
}

export const getProductsStart = () => ({
	type: START_DOWNLOAD_PRODUCTS
});

export const downloadProductsSuccess = products => ({
	type: DOWNLOAD_PRODUCTS_SUCCESS,
	payload: products
});

export const downloadProductsErr = () => ({
	type: DOWNLOAD_PRODUCTS_ERR
});

//funcion que elimina un producto en especifico
export function detleteProductAction (id) {
	return (dispatch) => {
		dispatch( getProductDelete() );

		//aqui lo elimina de la api
		clientAxios.delete(`/books/${id}`)
			.then(res => {
				console.log(res);
				//aqui lo elimina del state 
				dispatch( productDeleteSuccess(id) );
			}).catch(err => {
				console.log(err);
				dispatch( productDeleteErr() );
			})
	}
}

export const getProductDelete = () => ({
	type: GET_PRODUCT_DELETE
});

export const productDeleteSuccess = (id) => ({
	type: PRODUCT_DELETE_SUCCESS,
	payload: id
});

export const productDeleteErr = () => ({
	type: PRODUCT_DELETE_ERR
});


//funcion que edita un producto en especifico
export function editProductAction (id) {
	return (dispatch) => {
		dispatch( getProductEdit() );

		//aqui lo edita de la api
		clientAxios.get(`/books/${id}`)
			.then(res => {
				console.log(res);
				//aqui lo elimina del state 
				dispatch( productEditSuccess(res.data) );
			}).catch(err => {
				console.log(err);
				dispatch( productEditErr() );
			})
	}
}

export const getProductEdit = () => ({
	type: GET_PRODUCT_EDIT
});

export const productEditSuccess = (product) => ({
	type: PRODUCT_EDIT_SUCCESS,
	payload: product
});

export const productEditErr = () => ({
	type: PRODUCT_DELETE_ERR
});

//modifica un producto en la api y state 
export function editionProductAction( product ) {
	return (dispatch) => {
		dispatch( startEditionProduct() );
		clientAxios.put(`/books/${product.id}`, product)
			.then(res => {
				console.log(res);
				dispatch( productEditedSuccess(res.data) );
			}).catch(err => {
				console.log(err);
				dispatch( productEditedErr() );
			})
	}
}

export const startEditionProduct = () => ({
	type: START_EDITION_PRODUCT
});

export const productEditedSuccess = product => ({
	type: PRODUCT_EDITED_SUCCESS,
	payload: product
});

export const productEditedErr = () => ({
	type: PRODUCT_EDITED_ERR
});