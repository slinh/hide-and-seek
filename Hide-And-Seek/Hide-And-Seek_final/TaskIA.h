#ifndef TASK_IA_H
#define TASK_IA_H

#include "config.h"
#include "Assert.h"
#include "Alloc.h"
#include "Common.h"

namespace psp { namespace ia {

template < typename T, void (T::*OnTimerFn)() >
class TTaskIACallbackItem;


typedef enum typeTaskIA{
	TASKIA_RECURRENT = 1,
	TASKIA_UNIQUE = 2
} TypeTaskIA;

class TTaskIA
{
protected:
	// Eugen friend class TTaskIA ## SUFFIX ## Container;
	bool FRegistered;
	u32 FDateReveil;

	// type
	TypeTaskIA FType;

	void Register()
	{
		FRegistered = true;
	}
	void UnRegister()
	{
		FRegistered = false;
	}                                                                                                                           

public:
	
    TTaskIA(TypeTaskIA parType) : FRegistered(false), FDateReveil(0)
	{
		FType = parType;
	}
	
	GETTER_SETTER(u32, DateReveil)
	GETTER_SETTER(TypeTaskIA, Type)

    bool Registered() const                                                                                                     
    {												                                                                               
        return FRegistered;                                                                                                     
    }                                                                                                                           
    void Cancel_IFN()                                                                                                           
    {                                                                                                                           
        if (Registered())                                                                                                       
            Cancel();                                                                                                           
        LAssert(!Registered());                                                                                                  
    }

    void Terminate_IFN()                                                                                                        
    {                                                                                                                           
        if (Registered())                                                                                                       
        {                                                                                                                       
            Cancel();                                                                                                           
            LAssert(!Registered());                                                                                              
            OnTimer();                                                                                                          
        }                                                                                                                                                                                                             
        /* ne plus acceder a aucun membre champs/methode, this est peut être détruit dans OnTimer() */                          
    }    
	virtual void OnTimer() = 0; 
    void Cancel();                                                                                                              
    virtual ~TTaskIA();   

    void Wait(const u32 & value); 

	template < typename T, void (T::*OnTimerFn)() >                                                                            
    static TTaskIA* Make(T* self, TypeTaskIA parType);   
};

template < typename T, void (T::*OnTimerFn)() >                                                                                 
class TTaskIACallbackItem : public TTaskIA
{                                                                                                                               
    T* FSelf;       

    virtual void OnTimer()                                                                                             
    {                                                                                                                           
        (FSelf ->* OnTimerFn)();

		// si la tâche n'est pas recurrente, on l'enlève du managerIA
		if( FType == TASKIA_UNIQUE )
		{
			Cancel();
		}
		else
		{
			Wait(300);
		}
    }
public:
	TTaskIACallbackItem(T* self, TypeTaskIA parType)
	: TTaskIA(parType), FSelf(self)
	{
		LAssert(FSelf);
	}
};

template < typename T, void (T::*OnTimerFn)() >
TTaskIA* TTaskIA::Make(T* self, TypeTaskIA parType)
{
	return NEW_IN_DOMAIN(IA) TTaskIACallbackItem<T, OnTimerFn >(self, parType);
}

} // namespace ia
} // namespace psp

#endif

