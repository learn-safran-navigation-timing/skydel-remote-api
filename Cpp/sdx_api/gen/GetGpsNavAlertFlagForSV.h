#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GPS NAV Alert Flag
    ///
    /// Name Type Description
    /// ---- ---- -----------------------
    /// SvId int  Satellite's SV ID 1..32
    ///

    class GetGpsNavAlertFlagForSV;
    typedef std::shared_ptr<GetGpsNavAlertFlagForSV> GetGpsNavAlertFlagForSVPtr;
    
    
    class GetGpsNavAlertFlagForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsNavAlertFlagForSV();

      GetGpsNavAlertFlagForSV(int svId);
  
      static GetGpsNavAlertFlagForSVPtr create(int svId);
      static GetGpsNavAlertFlagForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

