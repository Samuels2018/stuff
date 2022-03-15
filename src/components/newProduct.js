import React, {useState} from 'react';
//mando a llamar las acciones
import {creteNewProductAction} from '../actions/productsActions';
import {validFomrAction, validationErr, validationSuccess } from '../actions/validationActions';
//esta funcion llama la siguiente accion
//useSelector se usa para aceder a un state
import {useDispatch, useSelector} from 'react-redux';


const NewProduct = ({history}) => {

	const [name, setName] = useState('');
	const [price, setPrice] = useState('');

	//crear nurevo producto 
	const dispatch = useDispatch();
	const addProduct = (product) => dispatch( creteNewProductAction(product) );
	//se manda a llamar la funcion validformAction 
	const validForm = () => dispatch( validFomrAction() );
	//se declara la funcion validationErr
	const errForm = () => dispatch( validationErr() );
	//se declara la funcion validationSuccess
	const successForm = () => dispatch( validationSuccess() );

	const err = useSelector((state) => state.err.err);

	const addNewProduct = (e)=> {
	
		e.preventDefault()

		validForm();

		//validar el formulario
		if (name.trim() === '' || price.trim() === ''){
			//se manda a llamar la funcion validationErr
			errForm();
			return;
		}

		//se manda a llamar la funcion validationSuccess
		successForm();

		//si pasa la validacion
		addProduct({
			name, price
		})

		history.push('/');
	}

	return (
	<div className='row justify-content-center mt-5'>
		<div className='col-md-8'>
			<div className='card'>
				<div className='card-body'>
					<h2 className='text-center mb-4 font-weight-bold'>Add New Product</h2>
					<form onSubmit={addNewProduct}>
						<div className='form-group'>
							<label>Name Product</label>
							<input type='text' className='form-control' placeholder='Name Product'
							value={name} onChange={e => setName(e.target.value)} />
						</div>

						<div>
							<label>Price Product</label>
							<input type='number' className='form-control' placeholder='Price Product'
							 value={price} onChange={e => setPrice(e.target.value)} />
						</div>
						<button type='submit' className='btn btn-primary font-weight-bold
						text-uppercase d-block w-100'>Add</button>
					</form>
					{err ? <div className='font-weight-bold alert alert-danger text-center mt-4'>
						All the Fields a Request
					</div>: null}
				</div>
			</div>
		</div>
	</div>
	);
}

export default NewProduct;