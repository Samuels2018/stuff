import {createStore, applyMiddleware, compose} from 'redux';
import thunk from 'redux-thunk';
import rootReducer from './reducers';

const initialState = {};
const middleware = [thunk];
// se crea el store 
const store = createStore(
	rootReducer,
	initialState,
	compose(applyMiddleware(...middleware),
		window.__REDUX_DEVTOOLS_EXTENSION__ && window.__REDUX_DEVTOOLS_EXTENSION__()
	)
);

/* es el encargado de la aplicacion*/
// este store se requiere en el componente principal
//para que fluyan los datos
export default store;	