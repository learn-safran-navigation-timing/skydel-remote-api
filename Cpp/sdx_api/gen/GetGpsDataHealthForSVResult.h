#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsDataHealthForSV
    ///
    /// Name   Type Description
    /// ------ ---- -----------------------
    /// SvId   int  Satellite's SV ID 1..32
    /// Health int  Data health 0..7
    ///

    class GetGpsDataHealthForSVResult;
    typedef std::shared_ptr<GetGpsDataHealthForSVResult> GetGpsDataHealthForSVResultPtr;
    
    
    class GetGpsDataHealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGpsDataHealthForSVResult();

      GetGpsDataHealthForSVResult(CommandBasePtr relatedCommand, int svId, int health);
  
      static GetGpsDataHealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, int health);
      static GetGpsDataHealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
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

