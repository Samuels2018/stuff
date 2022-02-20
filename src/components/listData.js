import React from 'react';

const ListData = ({dato}) => {

	const {name, url} = dato;


	return (
		<>

    <thead>
      <tr>
        <th scope="col">{name}</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <th scope="row">1</th>
        <td> <a href={url}>{url}</a></td>
      </tr>
              

    </tbody>

		 </>

	);


}

export default ListData;