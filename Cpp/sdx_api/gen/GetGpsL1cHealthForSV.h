#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GPS L1C health (used in CNAV2 only)
    ///
    /// Name Type Description
    /// ---- ---- -----------------------
    /// SvId int  Satellite's SV ID 1..32
    ///

    class GetGpsL1cHealthForSV;
    typedef std::shared_ptr<GetGpsL1cHealthForSV> GetGpsL1cHealthForSVPtr;
    
    
    class GetGpsL1cHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsL1cHealthForSV();

      GetGpsL1cHealthForSV(int svId);
  
      static GetGpsL1cHealthForSVPtr create(int svId);
      static GetGpsL1cHealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

