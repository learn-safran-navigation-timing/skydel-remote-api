#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GPS CNAV Alert Flag
    ///
    /// Name Type Description
    /// ---- ---- -----------------------
    /// SvId int  Satellite's SV ID 1..32
    ///

    class GetGpsCNavAlertFlagToSV;
    typedef std::shared_ptr<GetGpsCNavAlertFlagToSV> GetGpsCNavAlertFlagToSVPtr;
    
    
    class GetGpsCNavAlertFlagToSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsCNavAlertFlagToSV();

      GetGpsCNavAlertFlagToSV(int svId);
  
      static GetGpsCNavAlertFlagToSVPtr create(int svId);
      static GetGpsCNavAlertFlagToSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

