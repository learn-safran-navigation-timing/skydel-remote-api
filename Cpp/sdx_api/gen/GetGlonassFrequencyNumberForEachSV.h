#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get GLONASS frequency number for all satellites. Return values range from -7 to 13. Value -8 is an invalid value, it indicates that the almanac for the satellite is invalid.
    ///
    /// 
    ///

    class GetGlonassFrequencyNumberForEachSV;
    typedef std::shared_ptr<GetGlonassFrequencyNumberForEachSV> GetGlonassFrequencyNumberForEachSVPtr;
    
    
    class GetGlonassFrequencyNumberForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetGlonassFrequencyNumberForEachSV();

      static GetGlonassFrequencyNumberForEachSVPtr create();
      static GetGlonassFrequencyNumberForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;
    };
    
  }
}

