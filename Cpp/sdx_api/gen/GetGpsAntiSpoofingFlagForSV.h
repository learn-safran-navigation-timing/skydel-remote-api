#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GPS Anti-Spoofing Flag
    ///
    /// Name Type Description
    /// ---- ---- -----------------------
    /// SvId int  Satellite's SV ID 1..32
    ///

    class GetGpsAntiSpoofingFlagForSV;
    typedef std::shared_ptr<GetGpsAntiSpoofingFlagForSV> GetGpsAntiSpoofingFlagForSVPtr;
    
    
    class GetGpsAntiSpoofingFlagForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsAntiSpoofingFlagForSV();

      GetGpsAntiSpoofingFlagForSV(int svId);
  
      static GetGpsAntiSpoofingFlagForSVPtr create(int svId);
      static GetGpsAntiSpoofingFlagForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

