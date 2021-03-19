#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get NavIC NAV Alert Flag
    ///
    /// Name Type Description
    /// ---- ---- ---------------------
    /// SvId int  Satellite SV ID 1..14
    ///

    class GetNavICNavAlertFlagForSV;
    typedef std::shared_ptr<GetNavICNavAlertFlagForSV> GetNavICNavAlertFlagForSVPtr;
    
    
    class GetNavICNavAlertFlagForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetNavICNavAlertFlagForSV();

      GetNavICNavAlertFlagForSV(int svId);
  
      static GetNavICNavAlertFlagForSVPtr create(int svId);
      static GetNavICNavAlertFlagForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

