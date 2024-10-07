#pragma once

#include <memory>
#include "command_base.h"

#include "gen/SignalWithComponent.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the inter-modulation coefficient for this signal component. The default value is 1 for the signal component and 0 for the global inter-modulation coefficient.
    ///
    /// Name        Type                      Description
    /// ----------- ------------------------- --------------------
    /// SignalArray array SignalWithComponent Signals to multiply.
    ///

    class GetInterModulation;
    typedef std::shared_ptr<GetInterModulation> GetInterModulationPtr;
    
    
    class GetInterModulation : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetInterModulation();

      GetInterModulation(const std::vector<Sdx::SignalWithComponent>& signalArray);

      static GetInterModulationPtr create(const std::vector<Sdx::SignalWithComponent>& signalArray);
      static GetInterModulationPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** signalArray ****
      std::vector<Sdx::SignalWithComponent> signalArray() const;
      void setSignalArray(const std::vector<Sdx::SignalWithComponent>& signalArray);
    };
    
  }
}

