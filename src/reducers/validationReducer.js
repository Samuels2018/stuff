import {
	VALIDAR_FORM,
	VALIDAR_FORM_SUCCESS,
	VALIDAR_FORM_ERR
} from '../types';

//state intial 
const initalState = {
	err: null
}

export default function (state = initalState, action) {
	switch(action.type) {
		case VALIDAR_FORM:
			return {
				...state,
				err: null
			}

		case VALIDAR_FORM_SUCCESS: 
			return {
				...state,
				err: null
			}

		case VALIDAR_FORM_ERR:
			return {
				...state,
				err: true
			}

		default: return state;
	}
}