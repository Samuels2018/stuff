

// combine se usa para combinar
import { combineReducers } from 'redux';
// importo todos los reducers
import productsReducer from './productsReducer';
import validationReducer from './validationReducer';


export default combineReducers({
	products: productsReducer,
	err: validationReducer
});

/*este archivo combina los reducers*/