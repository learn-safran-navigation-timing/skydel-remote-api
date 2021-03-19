#pragma once

#include <memory>
#include "command_base.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GPS signal health
    ///
    /// Name Type Description
    /// ---- ---- -----------------------
    /// SvId int  Satellite's SV ID 1..32
    ///

    class GetGpsSignalHealthForSV;
    typedef std::shared_ptr<GetGpsSignalHealthForSV> GetGpsSignalHealthForSVPtr;
    
    
    class GetGpsSignalHealthForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSignalHealthForSV();

      GetGpsSignalHealthForSV(int svId);
  
      static GetGpsSignalHealthForSVPtr create(int svId);
      static GetGpsSignalHealthForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);
    };
  }
}

