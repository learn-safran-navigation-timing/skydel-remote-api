#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetBeiDouAutonomousHealthForSV
    ///
    /// Name   Type Description
    /// ------ ---- -------------------------------------
    /// SvId   int  Satellite SV ID 1..35
    /// Health bool Status, false = Good, true = Not Good
    ///

    class GetBeiDouAutonomousHealthForSVResult;
    typedef std::shared_ptr<GetBeiDouAutonomousHealthForSVResult> GetBeiDouAutonomousHealthForSVResultPtr;
    
    
    class GetBeiDouAutonomousHealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetBeiDouAutonomousHealthForSVResult();

      GetBeiDouAutonomousHealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health);
  
      static GetBeiDouAutonomousHealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health);
      static GetBeiDouAutonomousHealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      bool health() const;
      void setHealth(bool health);
    };
  }
}

