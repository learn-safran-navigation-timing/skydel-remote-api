#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get QZSS NAV Alert Flag
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// SvId int  Satellite SV ID 1..10
    ///

    class GetQzssNavAlertFlagForSV;
    typedef std::shared_ptr<GetQzssNavAlertFlagForSV> GetQzssNavAlertFlagForSVPtr;
    
    
    class GetQzssNavAlertFlagForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetQzssNavAlertFlagForSV();

      GetQzssNavAlertFlagForSV(int svId);
  
      static GetQzssNavAlertFlagForSVPtr create(int svId);
      static GetQzssNavAlertFlagForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

