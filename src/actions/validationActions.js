import {
	VALIDAR_FORM,
	VALIDAR_FORM_SUCCESS,
	VALIDAR_FORM_ERR
} from '../types';


export function validFomrAction() {
	return (dispatch)  => {
		dispatch( startValidation() )
	}
}

export const startValidation = () => {
	return{
		type: VALIDAR_FORM
	}
}

export const validationSuccess = () => {
	return{
		type: VALIDAR_FORM_SUCCESS
	}
}

export const validationErr = () => {
	return{
		type: VALIDAR_FORM_ERR
	}
}