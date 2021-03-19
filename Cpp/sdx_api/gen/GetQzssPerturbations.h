#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command QzssPerturbations is deprecated since 20.9. You may use Perturbations.
    /// 
    /// Get QZSS orbit perturbations (Crs, Crc, Cis, Cic, Cus and Cuc)
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// SvId int  Satellite SV ID 1..10
    ///

    class GetQzssPerturbations;
    typedef std::shared_ptr<GetQzssPerturbations> GetQzssPerturbationsPtr;
    
    
    class GetQzssPerturbations : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssPerturbations();

      GetQzssPerturbations(int svId);
  
      static GetQzssPerturbationsPtr create(int svId);
      static GetQzssPerturbationsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

