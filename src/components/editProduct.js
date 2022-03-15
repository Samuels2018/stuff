import React, {useEffect, Fragment, useRef} from 'react';
import {useDispatch, useSelector} from 'react-redux';
import {editProductAction, editionProductAction} from '../actions/productsActions';
import {validFomrAction, validationErr, validationSuccess } from '../actions/validationActions';



const EditProduct = ({match, history}) => {

	//crear los ref
	const nameRef = useRef('');
	const priceRef = useRef('');

	//dispatch para ejecutar la accion principal
	const dispatch = useDispatch();
	const editionProduct = (product) => dispatch( editionProductAction(product) );
	const validForm = () => dispatch( validFomrAction() );
	//se declara la funcion validationErr
	const errForm = () => dispatch( validationErr() );
	//se declara la funcion validationSuccess
	const successForm = () => dispatch( validationSuccess() );

	//obtener el id a editar 
	const {id} = match.params;

	useEffect(() => {
		dispatch( editProductAction(id) );
	}, [dispatch, id]);

	//acceder al state 
	const product = useSelector(state => state.products.product);
	const err = useSelector(state => state.products.err);

	//cuando carga la api
	if (!product) return 'Loanding...';

	const submitEditProduct = e => {
		e.preventDefault();
		console.log(nameRef.current.value);
		console.log(priceRef.current.value);

		//validar el form 
		validForm();


		//trim se usa para validar que no halla espacios en blanco
		if(nameRef.current.value.trim() === '' || priceRef.current.value.trim()) {
			errForm();
			return;
		}

		//no hay error guadar los cambios
		successForm();

		editionProduct({
			id,
			name: nameRef.current.value,
			price: priceRef.current.value
		}); 

		//redireccionar 
		history.push('/');
	}

	return (
	<Fragment>
	{err ? <div className='font-weight-bold alert alert-danger text-center mt-4'>
						All the Fields a Request
					</div>
		: <div className='row justify-content-center mt-5'>
			<div className='col-md-8'>
				<div className='card'>
					<div className='card-body'>
						<h2 className='text-center mb-4 font-weight-bold'>Edit Product</h2>
						<form onSubmit={submitEditProduct} >
							<div className='form-group'>
								<label>Title</label>
								<input type='text' className='form-control' placeholder='Title'
								defaultValue={product.name} 
								ref={nameRef} />
							</div>

							<div>
								<label>Price Product</label>
								<input type='number' className='form-control' placeholder='Price Product'
								defaultValue={product.price} ref={priceRef} />
							</div>
							<button type='submit' className='btn btn-primary font-weight-bold
							text-uppercase d-block w-100'>Save Changes</button>
						</form>
					</div>
				</div>
			</div>
		</div>}
	</Fragment>
	);
}

export default EditProduct;