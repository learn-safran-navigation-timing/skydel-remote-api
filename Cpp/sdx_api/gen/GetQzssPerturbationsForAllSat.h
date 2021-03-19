#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command QzssPerturbationsForAllSat is deprecated since 20.9. You may use PerturbationsForAllSat.
    /// 
    /// Get QZSS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) for all satellites.
    /// All parameters are zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///
    /// 
    ///

    class GetQzssPerturbationsForAllSat;
    typedef std::shared_ptr<GetQzssPerturbationsForAllSat> GetQzssPerturbationsForAllSatPtr;
    
    
    class GetQzssPerturbationsForAllSat : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssPerturbationsForAllSat();
  
      static GetQzssPerturbationsForAllSatPtr create();
      static GetQzssPerturbationsForAllSatPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
  }
}

