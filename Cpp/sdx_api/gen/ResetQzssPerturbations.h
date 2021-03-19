#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command ResetQzssPerturbations is deprecated since 20.9. You may use ResetPerturbations.
    /// 
    /// Set QZSS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc) to zero
    ///
    /// Name Type Description
    /// ---- ---- --------------------------------------------------------------------
    /// SvId int  Satellite SV ID 1..10, or use 0 to apply new value to all satellites
    ///

    class ResetQzssPerturbations;
    typedef std::shared_ptr<ResetQzssPerturbations> ResetQzssPerturbationsPtr;
    
    
    class ResetQzssPerturbations : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ResetQzssPerturbations();

      ResetQzssPerturbations(int svId);
  
      static ResetQzssPerturbationsPtr create(int svId);
      static ResetQzssPerturbationsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

