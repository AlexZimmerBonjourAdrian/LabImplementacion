#include "time.h"
class DtFecha :: public ICollectible
{
private:
    time_t FechaHora;
    
public:
    DtFecha(time_t FechaHora);
    time_t getFechaHora();
   virtual ~DtFecha();
};

