#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsSignalHealthForSV.
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------
    /// SvId   int  Satellite's SV ID 1..32
    /// Health int  Signal health 0..31
    ///

    class GetGpsSignalHealthForSVResult;
    typedef std::shared_ptr<GetGpsSignalHealthForSVResult> GetGpsSignalHealthForSVResultPtr;
    
    
    class GetGpsSignalHealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsSignalHealthForSVResult();

      GetGpsSignalHealthForSVResult(CommandBasePtr relatedCommand, int svId, int health);
  
      static GetGpsSignalHealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, int health);
      static GetGpsSignalHealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      int health() const;
      void setHealth(int health);
    };
  }
}

