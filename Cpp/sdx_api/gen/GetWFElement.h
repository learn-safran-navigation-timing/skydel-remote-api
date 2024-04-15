#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get Wavefront element properties. Properties define if an element is enabled/disabled, and the associated antenna.
    ///
    /// Name    Type Description
    /// ------- ---- -----------------------------------------------------------------------------------
    /// Element int  One-based index of the element. Value -1 adds a new element at the end of the list.
    ///

    class GetWFElement;
    typedef std::shared_ptr<GetWFElement> GetWFElementPtr;
    
    
    class GetWFElement : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetWFElement();

      GetWFElement(int element);

      static GetWFElementPtr create(int element);
      static GetWFElementPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** element ****
      int element() const;
      void setElement(int element);
    };
    
  }
}

