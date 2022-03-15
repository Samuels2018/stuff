	
// importo los types
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

//cada reducer tiene su propio state
// el estate es un objeto
// y cada state tine sus propiedades 
// cuando ienes un listado se declara como array
const initialState = {
	products : [],
	err: null,
	loading: false,
	product: {}
}

// luego viene una funcion donde se le envia el state y una action
// todo el reducer es un switch
export default function(state = initialState, action) {
	// siempre va un action type
	switch(action.type) {
		// van todos los casos que van a describir lo que pasa en la aplicacion
		case ADD_PRODUCT :
			return {
				...state,
				err: null,
				loading: false
			}
		case ADD_PRODUCT_SUCCESS :
			return {
				...state,
				err: null,
				loading: false,
				products: [...state.products, action.payload]
			}

		case ADD_PRODUCT_ERR: 
			return {
				...state,
				err: true,
				loading: false
			}

		case START_DOWNLOAD_PRODUCTS:
			return{
				...state,
				loading: true,
				product: {}
			}

		case DOWNLOAD_PRODUCTS_SUCCESS:
			return{
				...state,
				products: action.payload,
				loading: false,
				err: false,
				product: {}
			}

		case DOWNLOAD_PRODUCTS_ERR:
			return{
				...state,
				products: [],
				err: true,
				loading: false,
				product: {}
			}

		case GET_PRODUCT_DELETE:
			return{
				...state,
				err: null
			}

		case PRODUCT_DELETE_SUCCESS:
			return{
				...state,
				err: null,
				products: state.products.filter( product => product.id !== action.payload )
			}

		case PRODUCT_DELETE_ERR:
			return{
				...state,
				err: true
			}

		case GET_PRODUCT_EDIT:
			return{
				...state,
				err: null
			}

		case PRODUCT_EDIT_SUCCESS:
			return{
				...state,
				err: null,
				product: action.payload
			}

		case PRODUCT_EDIT_ERR:
			return{
				...state,
				err:true
			}

		case START_EDITION_PRODUCT:
			return{
				...state,
				err: null
			}

		case PRODUCT_EDITED_SUCCESS:
			return{
				...state,
				err: null,
				products: state.products.map(product => product.id === action.payload.id 
					? product = action.payload : product)
			}

		case PRODUCT_EDITED_ERR:
			return{
				...state,
				err: true
			}

		default: return state;
	}
}