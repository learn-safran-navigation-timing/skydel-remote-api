#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of IsGpsSatMotionFixed.
    ///
    /// Name    Type Description
    /// ------- ---- --------------------------------------------------------------------------------------------------------------
    /// Prn     int  Satellite PRN number
    /// IsFixed bool If true, the satellite relative position is fixed, if false, the satellite motion follows a normal trajectory.
    ///

    class IsGpsSatMotionFixedResult;
    typedef std::shared_ptr<IsGpsSatMotionFixedResult> IsGpsSatMotionFixedResultPtr;
    
    
    class IsGpsSatMotionFixedResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsGpsSatMotionFixedResult();

      IsGpsSatMotionFixedResult(CommandBasePtr relatedCommand, int prn, bool isFixed);
  
      static IsGpsSatMotionFixedResultPtr create(CommandBasePtr relatedCommand, int prn, bool isFixed);
      static IsGpsSatMotionFixedResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** prn ****
      int prn() const;
      void setPrn(int prn);


      // **** isFixed ****
      bool isFixed() const;
      void setIsFixed(bool isFixed);
    };
  }
}

