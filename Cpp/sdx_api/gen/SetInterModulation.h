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
    /// Set the inter-modulation coefficient for this signal component. The default value is 1 for the signal component and 0 for the global inter-modulation coefficient.
    ///
    /// Name        Type                      Description
    /// ----------- ------------------------- -------------------------
    /// SignalArray array SignalWithComponent Signals to multiply.
    /// Coefficient double                    The coefficient to apply.
    ///

    class SetInterModulation;
    typedef std::shared_ptr<SetInterModulation> SetInterModulationPtr;
    
    
    class SetInterModulation : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetInterModulation();

      SetInterModulation(const std::vector<Sdx::SignalWithComponent>& signalArray, double coefficient);

      static SetInterModulationPtr create(const std::vector<Sdx::SignalWithComponent>& signalArray, double coefficient);
      static SetInterModulationPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** signalArray ****
      std::vector<Sdx::SignalWithComponent> signalArray() const;
      void setSignalArray(const std::vector<Sdx::SignalWithComponent>& signalArray);


      // **** coefficient ****
      double coefficient() const;
      void setCoefficient(double coefficient);
    };
    
  }
}

