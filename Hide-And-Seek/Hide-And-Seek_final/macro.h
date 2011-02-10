#ifndef MACRO_H
#define MACRO_H

#define STRINGIZE(s) #s

#define VIRTUAL_DESTRUCTOR(CLASS_TYPE) virtual ~CLASS_TYPE() {}

#define NON_COPYABLE(CLASS_TYPE) private: \
									CLASS_TYPE(const CLASS_TYPE& parClass); \
									CLASS_TYPE& operator=(const CLASS_TYPE& parClass);

#define GETTER(VAR_TYPE, VAR_NAME_WITHOUT_F) inline const VAR_TYPE& Get## VAR_NAME_WITHOUT_F() const {return F## VAR_NAME_WITHOUT_F;}

#define SETTER(VAR_TYPE, VAR_NAME_WITHOUT_F) inline VAR_TYPE& Set## VAR_NAME_WITHOUT_F() {return F## VAR_NAME_WITHOUT_F;}

#define GETTER_SETTER(VAR_TYPE, VAR_NAME_WITHOUT_F) GETTER(VAR_TYPE, VAR_NAME_WITHOUT_F) \
													SETTER(VAR_TYPE, VAR_NAME_WITHOUT_F)


#define GETTER_NEW(VAR_TYPE, VAR_NAME_WITHOUT_F) inline const VAR_TYPE& VAR_NAME_WITHOUT_F() const {return F## VAR_NAME_WITHOUT_F;}

#define SETTER_NEW(VAR_TYPE, VAR_NAME_WITHOUT_F) inline VAR_TYPE& VAR_NAME_WITHOUT_F() {return F## VAR_NAME_WITHOUT_F;}

#define GETTER_SETTER_NEW(VAR_TYPE, VAR_NAME_WITHOUT_F) GETTER_NEW(VAR_TYPE, VAR_NAME_WITHOUT_F) \
														SETTER_NEW(VAR_TYPE, VAR_NAME_WITHOUT_F)

#define GETTER_PTR(VAR_TYPE, PTR_NAME_WITHOUT_F) inline VAR_TYPE* Get## PTR_NAME_WITHOUT_F() const {return F## PTR_NAME_WITHOUT_F;}

#define SETTER_PTR(VAR_TYPE, PTR_NAME_WITHOUT_F) inline void Set## PTR_NAME_WITHOUT_F(VAR_TYPE* parValue) {F## PTR_NAME_WITHOUT_F = parValue;}

#define GETTER_SETTER_PTR(VAR_TYPE, PTR_NAME_WITHOUT_F) GETTER_PTR(VAR_TYPE, PTR_NAME_WITHOUT_F) \
														SETTER_PTR(VAR_TYPE, PTR_NAME_WITHOUT_F)

#define DESERIALIZE(buffer, type) *((type*)buffer); \
	buffer += sizeof(type);
    
#define SERIALIZE(buffer, type, var) *((type*)buffer) = var; \
	buffer += sizeof(type);

#endif
