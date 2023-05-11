#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the WF antenna offset infos for this element.
    ///
    /// Name    Type Description
    /// ------- ---- ---------------------------------------
    /// Element int  One-based index for element in antenna.
    ///

    class GetWFAntennaElementOffset;
    typedef std::shared_ptr<GetWFAntennaElementOffset> GetWFAntennaElementOffsetPtr;
    
    
    class GetWFAntennaElementOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetWFAntennaElementOffset();

      GetWFAntennaElementOffset(int element);

      static GetWFAntennaElementOffsetPtr create(int element);
      static GetWFAntennaElementOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** element ****
      int element() const;
      void setElement(int element);
    };
    
  }
}

