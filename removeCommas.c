int removeCommas ( char *commaStr ) {

	int length = 0;
	int i;
	int numCommas = 0;

	length = strlen (commaStr);

	for ( i = 0; i < length; i++) {
		if ( commaStr[i] == ',') {
			numCommas ++;
			commaStr[i] = commaStr[i + numCommas];
		}

		else {
			commaStr[i] = commaStr[i + numCommas];
		}
	}

	return numCommas;

}
