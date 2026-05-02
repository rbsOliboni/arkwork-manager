

/*******************************************************************/
// Here are two models that can be used:


// "
int a1=atoi(std::string("1145911247").c_str()); 
int a2=atoi(std::string("1864092950").c_str());
int a3=atoi(std::string("1526257490").c_str());
int a4=atoi(std::string("597830625").c_str());

int a5=atoi(std::string("817793021").c_str());
int a6=atoi(std::string("924666508").c_str());
int a7=atoi(std::string("750763858").c_str());
int a8=atoi(std::string("1731629744").c_str());

static DWORD s_adwEterPackKey[] =
{
	// 1145911247,
	// 1864092950,
	// 1526257490,
	// 597830625,
	a1,a2,a3,a4
};

static DWORD s_adwEterPackSecurityKey[] =
{
	// 817793021,
	// 924666508,
	// 750763858,
	// 1731629744,
	a5,a6,a7,a8
};
// "

/*******************************************************************/
// -- Or the newest version: both are compatible.


// "
static DWORD s_adwEterPackKey[] =
{
	1145911247,
	1864092950,
	1526257490,
	597830625,
};

static DWORD s_adwEterPackSecurityKey[] =
{
	817793021,
	924666508,
	750763858,
	1731629744,
};
// "


/*******************************************************************/
// replace with:
// The new password can be generated within "ArkWork-Manager.exe" in Conversion.

static const char s_szEterPackKeyPassword[] = "betuf9-diwuf7-foma3-xade7-xuna9-bigi7";
static const char s_szEterPackSecurityKeyPassword[] = "gaju2-jafu7-caga3-xino4-wufo8-lem5";

static DWORD s_adwEterPackKey[4] = { 0, 0, 0, 0 };
static DWORD s_adwEterPackSecurityKey[4] = { 0, 0, 0, 0 };
static bool s_bEterPackKeysInitialized = false;

static void DeriveEterPackKey(const char* c_szPassword, DWORD* pdwKey)
{
	BYTE digest[CryptoPP::SHA256::DIGESTSIZE];
	CryptoPP::SHA256 sha256;
	sha256.CalculateDigest(digest, reinterpret_cast<const BYTE*>(c_szPassword), strlen(c_szPassword));
	memcpy(pdwKey, digest, sizeof(DWORD) * 4);
}

static void EnsureEterPackKeys()
{
	if (s_bEterPackKeysInitialized)
		return;

	DeriveEterPackKey(s_szEterPackKeyPassword, s_adwEterPackKey);
	DeriveEterPackKey(s_szEterPackSecurityKeyPassword, s_adwEterPackSecurityKey);
	s_bEterPackKeysInitialized = true;
}

static DWORD* GetEterPackKey()
{
	EnsureEterPackKeys();
	return s_adwEterPackKey;
}

static DWORD* GetEterPackSecurityKey()
{
	EnsureEterPackKeys();
	return s_adwEterPackSecurityKey;
}



/*******************************************************************/
// Search:

	BYTE * pbData = new BYTE[file.Size()];
	memcpy(pbData, pvData, file.Size());

	CLZObject zObj;

// Replace:

	if (!CLZO::Instance().CompressEncryptedMemory(zObj, pbData, file.Size(), s_adwEterPackKey))

// for:

	if (!CLZO::Instance().CompressEncryptedMemory(zObj, pbData, file.Size(), GetEterPackKey()))




/*******************************************************************/
// Search:

	file.Destroy();

// Replace:

	while (!DeleteFile(m_indexFileName));

// for:

	while (!DeleteFileA(m_indexFileName));



/*******************************************************************/
// Search:

	else if (fourcc == CLZObject::ms_dwFourCC)
	{
		m_bEncrypted = true;

// Replace:

		if (!CLZO::Instance().Decompress(zObj, (const BYTE *) pvData, s_adwEterPackKey))

// for:

		if (!CLZO::Instance().Decompress(zObj, (const BYTE *) pvData, GetEterPackKey()))



/*******************************************************************/
// Search:

	else if (COMPRESSED_TYPE_SECURITY == index->compressed_type)
	{
		CLZObject * zObj = new CLZObject;

// Replace:

		if (!CLZO::Instance().Decompress(*zObj, static_cast<const BYTE *>(*data), s_adwEterPackSecurityKey))

// for:

		if (!CLZO::Instance().Decompress(*zObj, static_cast<const BYTE *>(*data), GetEterPackSecurityKey()))



/*******************************************************************/
// Search:

	else if (COMPRESSED_TYPE_SECURITY == index->compressed_type)
	{
		CLZObject * zObj = new CLZObject;

// Replace

		if (!CLZO::Instance().Decompress(*zObj, static_cast<const BYTE *>(*data), s_adwEterPackSecurityKey))

// for:

		if (!CLZO::Instance().Decompress(*zObj, static_cast<const BYTE *>(*data), GetEterPackSecurityKey()))



/*******************************************************************/
// Search:

bool CEterPack::Extract()
{
	...
		else if (COMPRESSED_TYPE_SECURITY == index->compressed_type)
		{

// Replace:

			if (!CLZO::Instance().Decompress(zObj, (const BYTE *) data + index->data_position, s_adwEterPackSecurityKey))

// for:

			if (!CLZO::Instance().Decompress(zObj, (const BYTE *) data + index->data_position, GetEterPackSecurityKey()))




/*******************************************************************/
// Search:

	TEterPackIndex * pIndex;
	pIndex = FindIndex(filename);

	CLZObject zObj;
	std::string encryptStr;

	if (packType == COMPRESSED_TYPE_SECURITY ||
		packType == COMPRESSED_TYPE_COMPRESS)
	{
		if (packType == COMPRESSED_TYPE_SECURITY)
		{

// Replace:

			if (!CLZO::Instance().CompressEncryptedMemory(zObj, data, len, s_adwEterPackSecurityKey))

// for:

			if (!CLZO::Instance().CompressEncryptedMemory(zObj, data, len, GetEterPackSecurityKey()))

