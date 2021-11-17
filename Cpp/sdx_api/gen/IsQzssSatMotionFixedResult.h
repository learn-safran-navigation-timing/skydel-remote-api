#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsQzssSatMotionFixed.
    ///
    /// Name    Type Description
    /// ------- ---- --------------------------------------------------------------------------------------------------------------
    /// SvId    int  Satellite SV ID number
    /// IsFixed bool If true, the satellite relative position is fixed, if false, the satellite motion follows a normal trajectory.
    ///

    class IsQzssSatMotionFixedResult;
    typedef std::shared_ptr<IsQzssSatMotionFixedResult> IsQzssSatMotionFixedResultPtr;
    
    
    class IsQzssSatMotionFixedResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsQzssSatMotionFixedResult();

      IsQzssSatMotionFixedResult(CommandBasePtr relatedCommand, int svId, bool isFixed);
  
      static IsQzssSatMotionFixedResultPtr create(CommandBasePtr relatedCommand, int svId, bool isFixed);
      static IsQzssSatMotionFixedResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** isFixed ****
      bool isFixed() const;
      void setIsFixed(bool isFixed);
    };
  }
}

